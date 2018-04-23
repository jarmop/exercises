// Lesson 5 Prefix Sums

function countDiv(A, B, K) {
  if (K > B && B !== 0) {
    return 0
  }
  if (A === B) {
    return A % K === 0 ? 1 : 0;
  }
  let i = A === 0 || K <= A ? A + A % K : K;
  let j = B - B % K;

  return ((j - i) / K) + 1;
}

let tests = [
  [11,14,2]
];

for (test of tests) {
  console.log(countDiv(...test));
}