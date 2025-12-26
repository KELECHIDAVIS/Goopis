# 1. Use Python as the base image
FROM python:3.10-slim

# 2. Install build tools: GCC, CMake, and Make
RUN apt-get update && apt-get install -y \
    gcc \
    g++ \
    cmake \
    make \
    && rm -rf /var/lib/apt/lists/*

# 3. Set the working directory
WORKDIR /app

# 4. Copy all project files
COPY . .

# 5. Build the C engine using your CMakeLists.txt
RUN mkdir build && cd build && \
    cmake .. -DCMAKE_BUILD_TYPE=Release && \
    make


# 6. Install Python dependencies
RUN pip install --no-cache-dir -r lichess-bot-master/requirements.txt

# 7. Start the bot (The Fix)
# We use /bin/sh to ensure we enter the directory before the python process starts
CMD cd /app/lichess-bot-master && python -u lichess-bot.py --config ../config.yml