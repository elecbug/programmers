using System;
using System.Collections.Generic;

public class Solution {
    public void BFS(int[,] computers, int n, List<int> list, int start) {
        Queue<int> queue = new Queue<int>();
        queue.Enqueue(start);
        list[start] = n;
        while (queue.Count != 0) {
            int num = queue.Dequeue();
            for (int i = 0; i < computers.GetLength(0); i++) {
                if (computers[i, num] == 1 && list[i] != n) {
                    list[i] = n;
                    queue.Enqueue(i);
                }
            }
        }
    }
    
    public int solution(int n, int[,] computers) {
        List<int> full_list = new List<int>(new int[n]);
        int k;
        for (k = 1; full_list.FindIndex((x)=>x == 0) != -1; k++) {
            for (int i = 0; i < n; i++) {
                if (full_list[i] == 0) {
                    BFS(computers, k, full_list, i);
                    break;
                }
            }
        }
        return k - 1;
    }
}