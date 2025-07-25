/*Name: Harry Yu
Date: 6/9/2023
Course: CS 290*/

//Copied code from zyBooks except for line 14

const express = require("express");
const app = express();

// Middleware that parses HTTP requests with JSON body
app.use(express.json());

app.use("/api/songs", require("./api/songs"));
app.use(express.static("public")); //Didn't use from zyBooks

app.listen(3000);