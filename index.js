#!/usr/bin/env node

const fs = require("fs")
const util = require("util")
const { execSync, execFile, execFileSync, spawn, exec } = require("child_process")
const path = "snowfall.o"

async function run() {
   try {
      if (!fs.existsSync(path)) {
         console.log("Running for the first time")
         await execSync(`gcc snowfall.c -o ${path}`, (err, stdout, stderr) => {
            if(stderr) return console.error(err);
         })
         console.log("Compiled successfully!")
      }

      exec("snowfall.o", (error, stdout, stderr) => {
         console.log(stdout)
      })
   } catch(err) {
      console.log(err)
   }
}

run()