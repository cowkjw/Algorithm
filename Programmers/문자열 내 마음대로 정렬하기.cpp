int N;

bool compare(string& s1, string& s2)
{

    if (s1[N] == s2[N]) // �ε��� ���� ���ٸ�
        return s1 < s2;
    else
        return s1[N] < s2[N];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;

    N = n;

    sort(strings.begin(), strings.end(), compare);

    answer = strings;

    return answer;
}