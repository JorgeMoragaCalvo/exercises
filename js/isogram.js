let str = "i-so-gram";

function is_isogram(str){
    size = str.length;
    while(size > 0){
        for(let i = size - 2; i >= 0; i--){
            if(str[size - 1] == str[i] 
                && (str[size - 1] != '-' && str[size - 1] != ' ')) return false;
        }
        size--;
    }
    return true;
}

console.log(is_isogram(str));

