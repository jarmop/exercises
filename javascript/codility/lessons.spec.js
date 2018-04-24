import each from 'jest-each';
import {prefixSums, sorting} from './lessons';

describe('prefixSums', () => {
    test('countDiv', () => {
      expect(prefixSums.countDiv(11, 14, 2)).toBe(2);
    });
  }
);

describe('sorting', () => {
  each([
    [
      [10,2,5,1,8,20],
      1
    ],
    [
      [10,50,5,1],
      0
    ],
    [
      [5,3,3],
      1
    ],
    [
      [1, 1, 2, 3, 5] ,
      0
    ],
  ]).test('triangle', (A, expected) => {
    expect(sorting.triangle(A)).toBe(expected);
  });
});
