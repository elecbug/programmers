using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public int solution(int n)
    {
        int sum = 0;
        Stack<int> stack = new Stack<int>();
        for(int j = 0; n != 0; j++)
        {
            stack.Push(n % 3);
            n /= 3;
        }
        for (int j = 0; 0 != stack.Count(); j++)
        {
            sum += stack.Pop() * (int)Math.Pow(3, j);
        }
        return sum;
    }
}