// Put your solution here
function divideArray(numbers) {
    const oddNums = [];
    const evenNums = [];
    for (i = 0; i < numbers.length; i++) {
        if (numbers[i] % 2 == 0) {
            evenNums.push(numbers[i]);
        }
        if (numbers[i] % 2 !== 0) {
            oddNums.push(numbers[i]);
        }
    }
    evenNums.sort((a, b) => a - b);
    oddNums.sort((a, b) => a - b);
    console.log("Even numbers:");
    if (evenNums.length === 0) {
        console.log("None");
    } 
    else {
        for (i = 0; i < evenNums.length; i++) {
            console.log(evenNums[i]);
        }
    }
    console.log("Odd numbers:");
    if (oddNums.length === 0) {
        console.log("None");
    } 
    else {
        for (i = 0; i < oddNums.length; i++) {
            console.log(oddNums[i]);
        }
    }
}