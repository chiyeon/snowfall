#!/usr/bin/env node

var   worldWidth = 80,
      worldHeight = 30,
      snowflakeSpawnChance = 3,
      sleepDuration = 300
var symbols = [
   "*", ".", "+"
]

function get_empty_world(width, height) {
   _world = []
   for (var i = 0; i < height * width; i++) _world[i] = i % width ? ' ' : '\n'
   return _world
}

function show_help() {
   console.log("USAGE: snowfall [-h] [-W/--width <width>] [-H/--height <height>] [-c/--chance <chance>] [-d/--duration <duration>]\n");
   console.log("All command line arguments are OPTIONAL.\n");
   console.log("               -h/--help: Prints this help menu");
   console.log("      -W/--width <width>: Sets the World Width (default: 80)");
   console.log("    -H/--height <height>: Sets the World Height (default: 30)");
   console.log("    -c/--chance <chance>: Sets the snowflake spawn chance (percent per tick) (default: 3)");
   console.log("-d/--duration <duration>: Sets the duration (in ms) of each tick (default: 300)");
}

function check_args(args) {
   if(args[2] == "-h" || args[2] == "--help") {
      show_help()
      return process.exit(0)
   }

   for (var i = 2; i < args.length - 1; i++) {
      console.log(args[i])
      switch(args[i]) {
         case "-W":
         case "--width":
            worldWidth = args[i + 1]
            break
         case "-H":
         case "--height":
            worldHeight = args[i + 1]
            break
         case "-c":
         case "--chance":
            snowflakeSpawnChance = args[i + 1]
            break
         case "-d":
         case "--duration":
            sleepDuration = args[i + 1]
            break
      }
   }
}

function start(world) {
   setInterval(() => {
      console.clear()
      console.log(world.join(""));
      for (var i = worldHeight * worldWidth; i > 0; i--) {	
         if(symbols.includes(world[i])) {			// make snowflakes fall & stack
            var dir = Math.floor(Math.random() * 3 - 1);
            var target = i + worldWidth + dir
            if(world[target] == ' ' && target > 0 && target < worldWidth * worldHeight) {
               world[target] = world[i]
               world[i] = ' ';
            }
         }																			// spawn snowflakes (focus *) under right conditions
         if(i < worldWidth && world[i + worldWidth] == ' ' && Math.random() * 100 <= snowflakeSpawnChance) {
            var s = Math.floor(Math.random() * (symbols.length))
            world[i] = symbols[s]
         }
      }
   }, sleepDuration)
}

check_args(process.argv)
start(get_empty_world(worldWidth, worldHeight))