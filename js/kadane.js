function kadane(arr){
    let size = arr.length;
    let max_so_far = Number.NEGATIVE_INFINITY;
    let max_ending_here = 0;

    for(let i = 0; i < size; i++){
        max_ending_here += arr[i];
        if(max_so_far < max_ending_here) max_so_far = max_ending_here;
        if(max_ending_here < 0) max_ending_here = 0;
    }
    return max_so_far;
}


let arr = [-2, -3, 4, -1, -2, 1, 5, -3];
console.log(kadane(arr));

/*
function kadane(arr) {
  const reduceFn = (acc, current) => {
    const newMax = Math.max(current, acc.max_ending_here + current);
    return {
      max_so_far: Math.max(acc.max_so_far, newMax),
      max_ending_here: newMax,
    };
  };

  const initialAcc = {
    max_so_far: Number.NEGATIVE_INFINITY,
    max_ending_here: 0,
  };

  const { max_so_far } = arr.reduce(reduceFn, initialAcc);
  return max_so_far;
}
*/