/*Name: Harry Yu
Date: 6/9/2023
Course: CS 290*/

//Code was copied from class

const Song = require("../models/song");
const router = require("express").Router();

// Get list of all songs in the database
router.get("/", function(req, res) {
   let query = {};
   // Check if genre was supplied in query string
   if (req.query.genre) {
      query = { genre: req.query.genre };
   }
   Song.find(query)
      .then((data)=> res.json(data))
      .catch((err)=> res.status(400).send(err));
});

// Add a new song to the database
router.post("/", function(req, res) {
   const song = new Song(req.body);
   song.save()
      .then((data)=> res.status(201).json(data))
      .catch((err)=> res.status(400).send(err));
});

//Delete a song from the database
router.delete("/:id", function(req, res) {
   Song.deleteOne({_id: req.params.id})
      .then((result) => {if (result.matchedCount === 0) {res.sendStatus(404);}
         else {res.sendStatus(204)}}).catch((err) => res.status(400).send(err));
});

//Update a song
router.get("/:id", function(req, res) {
   Song.findById(req.params.id).then((result) => res.json(result))
      .catch((err) => res.status(400).send(err));
});

//Update a song
router.put("/:id", function(req, res) {
   const song = req.body;
   Song.updateOne({_id: req.params.id}, song)
      .then((result) => {if (result.matchedCount === 0) {res.sendStatus(404);}
         else {res.sendStatus(204)}})
      .catch((err) => res.status(400).send(err));
});

module.exports = router;