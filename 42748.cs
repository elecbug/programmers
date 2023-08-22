using System;

public class Solution
{
    public int[] solution(int[] array, int[,] commands)
    {
        int[] answer = new int[commands.Length / 3];
        for (int i = 0; i < commands.Length / 3; i++)
        {
            int[] newArray = new int[commands[i, 1] - commands[i, 0] + 1];
            for (int j = 0; j < newArray.Length; j++)
            {
                newArray[j] = array[commands[i, 0] + j - 1];
            }
            Array.Sort<int>(newArray);
            answer[i] = newArray[commands[i, 2] - 1];
        }
        return answer;
    }
}