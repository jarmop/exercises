export const prefixSums = {
  countDiv: (A, B, K) => {
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
};

export const sorting = {
  triangle: (A) => {
    let hasTriangle = 0;
    let aLength = A.length;
    for (let i = 0; i < aLength - 2; i++) {
      let P = A[i];
      for (let j = i + 1; j < aLength - 1; j++) {
        let Q = A[j];
        for (let k = j + 1; k < aLength; k++) {
          let R = A[k];
          if (P + Q > R && Q + R > P && R + P > Q) {
            hasTriangle = 1;
            break;
          }
          if (hasTriangle) {
            break;
          }
        }
        if (hasTriangle) {
          break;
        }
      }
    }

    return hasTriangle;
  },
  distinct: (A) => {
    let distinct = {};
    A.forEach(value => distinct[value] = 1);

    return Object.keys(distinct).length;
  }
};