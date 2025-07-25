/*Name: Harry Yu
Date: 5/21/23
Course number: CS 290*/

//This function gets the values of the selected topic and count.
window.addEventListener("DOMContentLoaded", function () {
   document.querySelector("#fetchQuotesBtn").addEventListener("click", function () {

      // Get values from drop-downs
      const topicDropdown = document.querySelector("#topicSelection");
      const selectedTopic = topicDropdown.options[topicDropdown.selectedIndex].value;
      const countDropdown = document.querySelector("#countSelection");
      const selectedCount = countDropdown.options[countDropdown.selectedIndex].value;
   
      // Get and display quotes
      fetchQuotes(selectedTopic, selectedCount);	   
   });
});

// TODO: Modify to use Fetch API
//This function fetches the quotes and prints the quotes on the screen, based on the 
//topic and the number of quotes the user wants to see.
async function fetchQuotes(topic, count) {
   const location = "https://wp.zybooks.com/quotes.php?topic=" + topic + "&count=" + count; //copied from class
   const response = await fetch(location); //copied from class
   const message = document.getElementById("quotes");

   if (response.ok) { //copied from class
      const info = await response.json(); //copied from class
      console.log("ERROR: " + info.error); //testing line
      if (info.error) { //If there is an error fetching the quotes
         message.innerHTML = info.error;
      }
      else { //If there isn't an error fetching the quotes
         console.log("INFO: " + info); //testing line
         let html = "<ol>";
         for (let c = 0; c < count; c++) {
            html += `<li>${info[c].quote} - ${info[c].source}</li>`; //Print the quotes on the screen
         }
         html += "</ol>";
         document.querySelector("#quotes").innerHTML = html;
      }
   }
}
