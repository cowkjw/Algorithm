int N;

bool compare(string& s1, string& s2)
{

    if (s1[N] == s2[N]) // 인덱스 값이 같다면
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