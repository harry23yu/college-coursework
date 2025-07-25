/*Name: Harry Yu
Date: 6/9/2023
Course: CS 290*/

//Copied code from zyBooks except for the URL on line 8

const mongoose = require("mongoose");
mongoose.connect("mongodb+srv://harry23yu:test@cluster0.mch2klu.mongodb.net/music_db?retryWrites=true&w=majority");
module.exports = mongoose;