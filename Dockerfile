# 1. Use Python 3.10-slim as the base image
FROM python:3.10-slim

# 2. Install build dependencies for the engine
RUN apt-get update && apt-get install -y \
    gcc \
    g++ \
    cmake \
    make \
    && rm -rf /var/lib/apt/lists/*

# 3. Set the initial working directory
WORKDIR /app

# 4. Copy everything from your local project into the container
COPY . .

# 5. Move config.yml into the subdirectory where the bot script lives
# This ensures config.yml is found and its relative paths (../) are correct
RUN cp config.yml lichess-bot-master/config.yml

# 6. Build your engine
RUN mkdir build && cd build && \
    cmake .. -DCMAKE_BUILD_TYPE=Release && \
    make

# 7. Install Python requirements for the bot
RUN pip install --no-cache-dir -r lichess-bot-master/requirements.txt

# 8. Start the bot from inside its master folder
WORKDIR /app/lichess-bot-master
CMD ["python", "lichess-bot.py"]