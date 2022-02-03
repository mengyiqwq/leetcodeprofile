#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <unistd.h>
#include <istream>
using namespace std;
// 检测文件大小的程序
long testSize(const char *filename)
{
    long l, r;
    ifstream file(filename);
    r = file.tellg();
    file.seekg(0, ios::end);
    l = file.tellg();
    file.close();
    // cout << "当前文件大小为" << (l - r) / 1024 << "KB";
    return (l - r);
}
// 生成文件的程序
void createAfile(const char *filename, string txt = "this is a txt", int nums = 1)
{
    string rename;
    string tail;
    ofstream file(filename);
    if (file.is_open())
    {
        // cout << "文件已经打开";
        file << txt;
    }
    int offset = 0;
    while (*(filename + offset) != '.' && *(filename + offset) != 0)
    {
        rename += *(filename + offset);
        offset++;
    }
    while (*(filename + offset) != 0)
    {
        tail += *(filename + offset);
        offset++;
    }
    file.close();
    while (nums > 1)
    {
        // cout<<"new file:"<<filename<<"is created!"<<endl;
        file.open(rename + to_string(nums - 1) + tail);
        if (file.is_open())
        {
            cout<<"the content of "<<rename + to_string(nums - 1) + tail<<":";
            cin>>txt;
            file << txt;
        }
        file.close();
        nums--;
    }
    cout << "finished!......" << endl;
}
// 缓存中读或者写入文件
void bufferOp(const char *filename)
{
    char *buffer;
    long size;
    ifstream file(filename);
    size = testSize(filename);
    buffer = new char[size];
    file.read(buffer, size);
    file.close();
    delete[] buffer;
}
// 希望写出一个可以自动帮助我删除所有exe文件的程序
void deleteexeFile(string filename, string tail = "*.txt", char *path = nullptr)
{
    // remove(filename);
    if (path == nullptr)
    {
        path = getcwd(NULL, 0);
        puts(path);
        // cout << "path:" << path;
    }
    ofstream file(filename);
    string pah = "\"";
    for (int i = 0; i < 255; i++)
    {
        if (*(path + i) == '\000')
            break;
        pah.push_back(*(path + i));
    }
    pah += "\\" + tail + "\"";
    if (file.is_open())
    {
        cout << "the file is opened succefully" << endl;
        file << "del /a /f /s /q " + pah;
        // cout<<"路径"<<*path;
        // cout << "finished";
    }
    free(path);
    cout << "The file with " << tail << " is removed!" << endl;
}
void exethedat(const char *filename)
{
    system(filename);
}
int main()
{
    string tail;
    string path;
    int nums;
    string iscreateAfile;
    string filename;
    string txt;
    cout << setw(85) << setfill(' ') << "---the program is used for deleting some files---" << setfill('-') << endl
         << "Do you want to create a file?(1/0):";
    cin >> iscreateAfile;
    if (iscreateAfile == "1")
    {
        cout << "your filename:";
        cin >> filename;
        cout << "your content:";
        cin >> txt;
        cout << "your nums:";
        cin >> nums;
        createAfile(filename.c_str(), txt, nums);
    }
    cout << endl
         << "the tail name of the file :";
    cin >> tail;
    cout << endl
         << "the path of the file(if using current path,please input -1):";
    cin >> path;
    if (path != "-1")
    {
        char *k = (char *)malloc((path.size() + 1) * sizeof(char));
        deleteexeFile("d.dat", tail);
    }
    else
        deleteexeFile("d.bat", tail);
    exethedat("d.bat");
    remove("d.bat");
    system("pause");
}