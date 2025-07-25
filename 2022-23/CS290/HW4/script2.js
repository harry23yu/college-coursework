// Your solution goes here 
function hasUpperCase(str) {
    return str !== str.toLowerCase();
}

function isStrongPassword(password) {
    if (password.length >= 8) {
        if (!(password.includes("password"))) {
            if (hasUpperCase(password)) {
                return true;
            }
        }
    } 
    return false;
}