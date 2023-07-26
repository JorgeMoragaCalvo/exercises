function digits(num){
    let count = 0;
    while(num>0){
        num = Math.floor(num/10);
        count++;
    }
    return count;
}

function isArmstrong(num){
    if(num == 0) return true;
    else{
        let sum = 0;
        let aux = num;
        let d = digits(num);
        let i = d - 1;
        while(i >= 0){
            let a = Math.floor(num / (Math.pow(10, i)));
            sum += Math.pow(a, d);
            num = num % Math.pow(10, i);
            i--;
        }
        return sum == aux;
    }
    
}

let num = 371;
console.log(isArmstrong(num));