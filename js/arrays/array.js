const cities = ['New York', 'London', 'Paris', 'Berlin'];
cities.forEach(city => console.log(city));

cities.push('Santiago'); // add to the end
// add to the beginning cities.unshift('Sydney');
console.log(typeof cities);
// remove from the end cities.pop();
// remove from the beginning cities.shift();
console.log(cities.length);

cities.forEach(function(elemento, indice){
    console.log(elemento, indice);
})

console.log(cities.indexOf('London'))
cities.splice(1, 2); // a -> desde que indice. b -> indica cuantos elementos a partir del indice a
console.log(cities);

let citiesCopy = cities.slice(); //copia del Array
console.log(Object.keys(cities)); //ver indices que ocupa el array
console.log(Array.isArray(cities)); //true
console.log(cities.reverse());
console.log(cities.sort());

var numbers = [1, 2, 3, 4, 5, 6];
var doubles = numbers.map(function(x) {
    return x * 2;
});

console.log(doubles);

//******************* ARROW FUNCTION ******************/
let a = 4;
let b = 2;
console.log(() => a + b + 100);

