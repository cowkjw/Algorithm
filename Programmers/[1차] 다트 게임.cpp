#include <string>
#include <cmath>
using namespace std;


int solution(string dartResult) {

    int answer = 0, prev = 0, point = 0, count = 0;
    bool prevStar = false;
    bool sharp = false;


    for (int i = 0; i < dartResult.size(); i++)
    {
        if (dartResult[i] >= '0' && dartResult[i] <= '9')
        {
            count++; // 숫자 카운트
            if (dartResult[i + 1] == '0')
            {
                if (dartResult[i + 2] == 'S')
                {
                    point = 10;
                    if (dartResult[i + 3] == '*')
                    {
                        if (count == 1) // 맨 처음에 등장한 별인지 판단
                        {
                            answer += point * 2;
                        }
                        if (prevStar)
                        {
                            answer += (prev * 2) + (point * 2);
                        }
                        else if (count != 1 && !prevStar)
                        {
                            answer += prev + (point * 2);
                        }
                        prevStar = true; // 이전에 별이 있었는지 판단
                    }
                    else if (dartResult[i + 3] == '#')
                    {
                        answer += point * -1;
                        sharp = true;
                        if (prevStar) // 만약 이전에 별이였는데 다시 샵이기 때문에 다음 별을 위해서 false처리
                            prevStar = false;
                    }
                    else
                        answer += point;
                    if (sharp)
                    {
                        prev = point * -1;
                        sharp = false;
                    }
                    else
                        prev = point;
                }
                else if (dartResult[i + 2] == 'D')
                {
                    point = pow(10, 2);
                    if (dartResult[i + 3] == '*')
                    {
                        if (count == 1)
                        {
                            answer += point * 2;
                        }
                        if (prevStar)
                        {
                            answer += (prev * 2) + (point * 2);
                        }
                        else if (count != 1 && !prevStar)
                        {
                            answer += prev + (point * 2);
                        }
                        prevStar = true;
                    }
                    else if (dartResult[i + 3] == '#')
                    {
                        answer += point * -1;
                        sharp = true;
                        if (prevStar)
                            prevStar = false;
                    }
                    else
                        answer += point;
                    if (sharp)
                    {
                        prev = point * -1;
                        sharp = false;
                    }
                    else
                        prev = point;
                }
                else if (dartResult[i + 2] == 'T')
                {
                    point = pow(10, 3);
                    if (dartResult[i + 3] == '*')
                    {
                        if (count == 1)
                        {
                            answer += point * 2;
                        }
                        if (prevStar)
                        {
                            answer += (prev * 2) + (point * 2);
                        }
                        else if (count != 1 && !prevStar)
                        {
                            answer += prev + (point * 2);
                        }
                        prevStar = true;
                    }
                    else if (dartResult[i + 3] == '#')
                    {
                        answer += point * -1;
                        sharp = true;
                        if (prevStar)
                            prevStar = false;
                    }
                    else
                        answer += point;
                    if (sharp)
                    {
                        prev = point * -1;
                        sharp = false;
                    }
                    else
                        prev = point;
                }
                i++; // 10점이였기 때문에 하나 더 더해서 0을 넘기기
            }
            else // 10이 아닌 수들
            {
                if (dartResult[i + 1] == 'S')
                {
                    point = atoi(&dartResult[i]);
                    if (dartResult[i + 2] == '*')
                    {
                        if (count == 1)
                        {
                            answer += point * 2;
                        }
                        if (prevStar)
                        {
                            answer += (prev * 2) + (point * 2);
                        }
                        else if (count != 1 && !prevStar)
                        {
                            answer += prev + (point * 2);
                        }
                        prevStar = true;
                    }
                    else if (dartResult[i + 2] == '#')
                    {
                        answer += point * -1;
                        sharp = true;
                        if (prevStar)
                            prevStar = false;
                    }
                    else
                        answer += point;
                    if (sharp)
                    {
                        prev = point * -1;
                        sharp = false;
                    }
                    else
                        prev = point;
                }

                else if (dartResult[i + 1] == 'D')
                {

                    point = pow(atoi(&dartResult[i]), 2);
                    if (dartResult[i + 2] == '*')
                    {
                        if (count == 1)
                        {
                            answer += point * 2;
                        }
                        if (prevStar)
                        {
                            answer += (prev * 2) + (point * 2);
                        }
                        else if (count != 1 && !prevStar)
                        {
                            answer += prev + (point * 2);
                        }
                        prevStar = true;
                    }
                    else if (dartResult[i + 2] == '#')
                    {
                        answer += point * -1;
                        sharp = true;
                        if (prevStar)
                            prevStar = false;
                    }
                    else
                        answer += point;
                    if (sharp)
                    {
                        prev = point * -1;
                        sharp = false;
                    }
                    else
                        prev = point;
                }
                else if (dartResult[i + 1] == 'T')
                {

                    point = pow(atoi(&dartResult[i]), 3);
                    if (dartResult[i + 2] == '*')
                    {
                        if (count == 1)
                        {
                            answer += point * 2;
                        }
                        if (prevStar)
                        {
                            answer += (prev * 2) + (point * 2);
                        }
                        else if (count != 1 && !prevStar)
                        {
                            answer += prev + (point * 2);
                        }
                        prevStar = true;
                    }
                    else if (dartResult[i + 2] == '#')
                    {
                        answer += point * -1;
                        sharp = true;
                        if (prevStar)
                            prevStar = false;
                    }
                    else
                        answer += point;
                    if (sharp)
                    {
                        prev = point * -1;
                        sharp = false;
                    }
                    else
                        prev = point;
                }
            }

        }
    }

    return answer;
}
