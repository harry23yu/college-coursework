/*Name: Harry Yu
Date: 5/21/23
Course number: CS 290*/

class SuperHuman {
	constructor(name, powerLevel) {
		this.name = name;
		this.powerLevel = powerLevel;
	}
}

// Define SuperHero and SuperVillain classes here

class SuperHero extends SuperHuman {
	constructor(name, alias, powerLevel) {
		super(name, powerLevel);
		this.alias = alias;
	}
	battle(SuperVillain) {
		if (this.powerLevel >= SuperVillain.powerLevel) {
			return true;
		}
		else {
			return false;
		}
	}
}

class SuperVillain extends SuperHuman {
	constructor(name, alias, powerLevel) {
		super(name, powerLevel);
		this.alias = alias;
	}
	getEvilChuckle() {
		return "Ha ha ha!";
	}
}

const heroes = {
	"Super Bacon": new SuperHero("Jack Oinker", "Super Bacon", 2),
	"Flat-Man": new SuperHero("Peter Pranker", "Flat-Man", 5),
	"Mighty Woman": new SuperHero("Diana Dense", "Mighty Woman", 8),
	"Captain Marvelous": new SuperHero("Carol Hangers", "Captain Marvelous", 9)
};

const villains = {
	"The Jokester": new SuperVillain("Jack Nastier", "The Jokester", 3),
	"Magnet Man": new SuperVillain("Max Eisenhardt", "Magnet Man", 6),
	"Lex Loner": new SuperVillain("Lex Loner", "Lex Loner", 2),
	"Thankos": new SuperVillain("Thankos", "Thankos", 9)
};

registerHandlers();

//This function detects if the user selected a hero and villain.
function registerHandlers() {
	// Detect selection of hero and villain
	document.querySelector("#heroSelect").addEventListener("change", selectionChanged);
	document.querySelector("#villainSelect").addEventListener("change", selectionChanged);

	selectionChanged();
}

//This function gets the hero and villain selected and determines who won the battle.
function selectionChanged() {
	const selectedHeroValue = document.querySelector("#heroSelect").value;
	const selectedVillainValue = document.querySelector("#villainSelect").value;

	// Get hero and villain selected
	const selectedHero = heroes[selectedHeroValue];
	const selectedVillain = villains[selectedVillainValue];

	// Your code goes here
	var heroWon = selectedHero.battle(selectedVillain);
	var winner = document.getElementById("winner");
	if (heroWon) {
		winner.innerHTML = "Winner: " + selectedHero.alias + "!";
	}
	else {
		winner.innerHTML = "Winner: " + selectedVillain.alias + "!";
	}
}
