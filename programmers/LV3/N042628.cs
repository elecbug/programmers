using System;
using System.Collections.Generic;

public class Solution {
    public int binary_serach(List<int> arr, int element) {
        if (arr.Count == 0) {
            return 0;
        }
        if (arr[0] > element) {
            return 0;
        }
        else if (arr[arr.Count - 1] < element) {
            return arr.Count;
        }
        int min = 0, max = arr.Count;
        while (true) {
            if (min + 1 == max) {
                return max;
            }
            if (arr[(max + min) / 2] < element) {
                min = (max + min) / 2;
            }    
            else if (arr[(max + min) / 2] > element) {
                max = (max + min) / 2;
            }
            else {
                return (max + min) / 2;
            }
        }
    }
    
    public int[] solution(string[] operations) {
        List<int> binary_array = new List<int>();
        for (int i = 0; i < operations.Length; i++) {
            string[] split = operations[i].Split(' ');
            switch (split[0]) {
                case "I": {
                    int idx = binary_serach(binary_array, int.Parse(split[1]));
                    binary_array.Insert(idx, int.Parse(split[1]));
                } 
                    break;
                case "D": {
                    if (binary_array.Count > 0) {
                        switch (split[1]) {
                            case "1":
                                binary_array.RemoveAt(binary_array.Count - 1);
                                break;
                            case "-1":
                                binary_array.RemoveAt(0);
                                break;
                        }
                    }
                }
                    break;
            }
        }
        if (binary_array.Count > 0) {
            return new int[] {binary_array[binary_array.Count - 1], binary_array[0]};
        }
        else {
            return new int[] {0 ,0};
        }
    }
}