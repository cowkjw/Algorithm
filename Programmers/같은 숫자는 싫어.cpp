vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    int size = arr.size();


    for (int i = 0; i < size; i++)
    {
        if (arr[i] != arr[i + 1] && i != size - 1)
            answer.push_back(arr[i]);
        else if (i == size - 1)
            answer.push_back(arr[i]);

    }






    return answer;
}
