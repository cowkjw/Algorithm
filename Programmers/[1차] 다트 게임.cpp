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
            count++; // ���� ī��Ʈ
            if (dartResult[i + 1] == '0')
            {
                if (dartResult[i + 2] == 'S')
                {
                    point = 10;
                    if (dartResult[i + 3] == '*')
                    {
                        if (count == 1) // �� ó���� ������ ������ �Ǵ�
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
                        prevStar = true; // ������ ���� �־����� �Ǵ�
                    }
                    else if (dartResult[i + 3] == '#')
                    {
                        answer += point * -1;
                        sharp = true;
                        if (prevStar) // ���� ������ ���̿��µ� �ٽ� ���̱� ������ ���� ���� ���ؼ� falseó��
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
                i++; // 10���̿��� ������ �ϳ� �� ���ؼ� 0�� �ѱ��
            }
            else // 10�� �ƴ� ����
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
