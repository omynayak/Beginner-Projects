alert("Welcome to the basic Calculator!")
let choice = prompt("Would you like to begin? ").toLowerCase()
let value = 0
let flag = true

while(choice === "yes"){
    if(flag){
        value = Number(prompt("Enter the first number: "))
        flag = false
    }

    let operation = prompt("Choose: + - * / c").toLowerCase()

    switch (operation) {
        case '+': {
            let tempVal = Number(prompt("Enter the number: "))
            value += tempVal
            break;
        }

        case '-': {
            let tempVal = Number(prompt("Enter the number: "))
            value -= tempVal
            break;
        }

        case '*': {
            let tempVal = Number(prompt("Enter the number: "))
            value *= tempVal
            break;
        }

        case '/': {
            let tempVal = Number(prompt("Enter the number: "))
            while(tempVal === 0){
                tempVal = Number(prompt("Enter a non-zero value for division: "))
            }
            value /= tempVal
            break;
        }

        case 'c':
            value = 0
            flag = true
            alert("Value has been cleared!")
            break;

        default:
            alert("Invalid Operation choice")
            break;
    }

    alert(`The value is: ${value}`)
    choice = prompt("Would you like to continue?").toLowerCase()
}
alert("Thanks for swinging by!")