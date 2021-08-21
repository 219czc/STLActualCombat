#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
using namespace std;
#include <speechplayer.h>

#define SPEECHPLAYERNUM 24
#define SPEECHHUDGESNUM 10
#define SPEECHAGROUPNUM 6

map<float, int>* groupPlayerScore(vector<int> plyNumVec)
{
    map<float, int>* groupMap = new map<float, int>[plyNumVec.size() / SPEECHAGROUPNUM];
    for (int i = 0; i < plyNumVec.size() / SPEECHAGROUPNUM; i++) {
        for (int j = 0; j < SPEECHAGROUPNUM; j++) {
            deque<float> scoreVec; //���ÿλѧ���ɼ���
            float score;
            cout << "��ί���֣�" << endl;
            for (int l = 0; l < SPEECHHUDGESNUM; l++) {
                cin >> score;
                scoreVec.push_back(score);
                //if(cin.peek()!="/n")cout<<endl;
            }
            sort(scoreVec.begin(), scoreVec.end());
            scoreVec.pop_back();
            scoreVec.pop_front();
            score = accumulate(scoreVec.begin(), scoreVec.end(), 0.0f) / (SPEECHHUDGESNUM - 2);
            cout << "����+��ţ�" << score << " " << plyNumVec[(i + 1) * j] << endl;
            groupMap[i].insert(pair<float, int>(score, plyNumVec[(i * 6) + j]));
        }
    }
    cout << "��ţ�����";
    for (auto it : plyNumVec) {
        cout << it << " ";
    }
    cout << endl;
    return groupMap;
}

map<float, int>::iterator operator+(map<float, int>::iterator it, int pos)
{
    while (pos--) {
        it++;
    }
    return it;
}
vector<int>& getSpeechPromotionNum(vector<int>& plyNumVec, map<float, int>* groupMap, int groupNum, map<int, speechPlayer>& plymap)
{
    for (int i = 0; i < groupNum; i++) {

        map<float, int>::iterator it = groupMap[i].begin();
        //  map<float,int>::iterator it2=I
        for (auto it : groupMap[i]) {
            //   plyNumVec.push_back(it.second);
            cout << "ɾ��ǰ����" << i << "�飺" << it.first << "  " << it.second << endl;
        }
        for (auto it : groupMap[i]) {

            map<int, speechPlayer>::iterator splayer = plymap.find(it.second);
            (splayer->second).setScore(it.first);
        }
        groupMap[i].erase(it, it + 3);
        for (auto it : groupMap[i]) {
            plyNumVec.push_back(it.second);
        }
        groupMap[i].clear();
    }
    cout << "����ѡ�ֱ�ţ�" << endl;
    for (auto it : plyNumVec) {
        cout << it << " ";
    }
    cout << endl;
    return plyNumVec;
}
int main()
{
    speechPlayer* player = new speechPlayer[SPEECHPLAYERNUM]; //����ѧ�����������
    for (int i = 0; i < SPEECHPLAYERNUM; i++) {
        string name;
        cout << "������ѡ��������" << endl;
        cin >> name;
        (player + i)->setName(name);
    }
    map<int, speechPlayer> plymap;
    for (int i = 1; i <= SPEECHPLAYERNUM; i++) {
        plymap.insert(pair<int, speechPlayer>(i, *(player + i - 1)));
    }
    for (auto it : plymap) {
        cout << it.first << " " << it.second.getName() << endl;
    }
    vector<int> plyNumVec; //����
    for (int i = 1; i <= SPEECHPLAYERNUM; i++) {
        plyNumVec.push_back(i);
    }
    srand(time(0));
    random_shuffle(plyNumVec.begin(), plyNumVec.end());
    map<float, int>* groupMap = groupPlayerScore(plyNumVec);
    int groupNum = plyNumVec.size() / SPEECHAGROUPNUM;
    plyNumVec.clear();
    plyNumVec = getSpeechPromotionNum(plyNumVec, groupMap, groupNum, plymap);

    for (auto it : plyNumVec) {

        cout << "��ţ�" << it << " ������" << plymap[it].getName() << " �ɼ���" << (plymap[it].getScore())[plymap[it].getNum() - 1] << endl;
    }
    random_shuffle(plyNumVec.begin(), plyNumVec.end());
    groupMap = groupPlayerScore(plyNumVec);
    //plyNumVec.clear();
    groupNum = plyNumVec.size() / SPEECHAGROUPNUM;
    plyNumVec.clear();
    getSpeechPromotionNum(plyNumVec, groupMap, groupNum, plymap);

    for (auto it : plyNumVec) {

        cout << "��ţ�" << it << " ������" << plymap[it].getName() << " �ɼ���" << (plymap[it].getScore())[plymap[it].getNum() - 1] << endl;
    }
    random_shuffle(plyNumVec.begin(), plyNumVec.end());
    groupMap = groupPlayerScore(plyNumVec);
    groupNum = plyNumVec.size() / SPEECHAGROUPNUM;
    plyNumVec.clear();
    getSpeechPromotionNum(plyNumVec, groupMap, groupNum, plymap);

    for (auto it : plyNumVec) {

        cout << "��ţ�" << it << " ������" << plymap[it].getName() << " �ɼ���" << (plymap[it].getScore())[plymap[it].getNum() - 1] << endl;
    }
    return 0;
}
