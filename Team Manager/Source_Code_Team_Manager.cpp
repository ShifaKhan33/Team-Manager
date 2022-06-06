#include <bits/stdc++.h>
using namespace std;
void checkpotentialcontibuter(string Pskill, int Plevel,map<string, pair<string, int> > &finalcontributers, map<pair<string,int>, vector<pair<string,int> > > &Contributers){
    
    for(auto i :Contributers){
        for(pair<string,int> it: i.second){
            if(Pskill==it.first && Plevel <= it.second){
                finalcontributers[i.first.first]= make_pair(it.first, it.second+1);
                return;
            }
        }
    }
}
bool checkpotentialmentor(string Pskill, int Plevel, map<string, pair<string, int> > &finalcontributers, map<pair<string,int>, vector<pair<string,int> > > &Contributers){
    std::map<pair<string,int>, vector<pair<string,int> > >::iterator i = Contributers.begin();
    for(auto it: finalcontributers){
        if(Pskill==it.second.first && Plevel <= it.second.second && (*i).first.first!= it.first){
            finalcontributers[(*i).first.first]= {"None", 0};
            return true;
        }
        i++;
    } 
    return false;
}
void awardLevels(map<string, pair<string, int> > &finalcontributers,  map<pair<string,int>, vector<pair<string,int> > > &Contributers){
    for(auto &i:finalcontributers){
        for(auto &it: Contributers){
            if(i.first==it.first.first){ 
                for(auto &iter: it.second){
                    if(iter.first==i.second.first){
                        iter.second=i.second.second;
                    }
                    
                }

            }
        }
        
    }
}
int main()
{
    //***************************************Code for taking in number of projects and contributers from the file.**********************************

    string CandP, Contri, Pro, filename;
    int c, p, j = 0;
    cout << "Enter the input file's name which contains information about the Contributers and Projects.\n";
    cin >> filename;
    ifstream fromfile(filename);
    getline(fromfile, CandP);
    while (CandP[j] != ' ')
    {
        Contri += CandP[j];
        j++;
    }
    j++;
    while (j != CandP.size())
    {
        Pro += CandP[j];
        j++;
    }
    c = stoi(Contri);
    p = stoi(Pro);

    //****************************************************Code for storing contributer information in vectors.***************************************

    map<pair<string,int>, vector<pair<string,int> > > Contributers;
    vector<string> Cname(c); 
    vector<int> Cskills(c);
    vector<vector<string>> skillname(c);
    vector<vector<int>> level(c);
    for (int i = 0; i < c; i++)
    {
        string nameandskills;
        getline(fromfile, nameandskills);
        j = 0;
        while (nameandskills[j] != ' ')
        {  
            Cname[i] += nameandskills[j];
            j++;
        }
        string skills;
        while (j != nameandskills.size())
        {
            skills += nameandskills[j];
            j++;
        }
        Cskills[i] = stoi(skills);

        for (int k = 0; k < Cskills[i]; k++)
        {
            string skillandlevel;
            getline(fromfile, skillandlevel);
            j = 0;
            string s;
            while (skillandlevel[j] != ' ')
            {
                s += skillandlevel[j];
                j++;
            }
            skillname[i].push_back(s);
            string skilllevel = "";
            while (j != skillandlevel.size())
            {
                skilllevel += skillandlevel[j];
                j++;
            }
            level[i].push_back(stoi(skilllevel));
        }
    }
    for(int i=0; i<c; i++){
        vector<pair<string,int> > skillsandlevels;
        for(int j=0; j<Cskills[i]; j++){
            skillsandlevels.push_back({skillname[i][j], level[i][j]});
        }
        Contributers[{Cname[i],Cskills[i]}] = skillsandlevels;
    }

    //****************************************************Code for storing project information in vectors.*********************************************

    vector<string> Pname(p);
    vector<int> roles(p); 
    vector< vector<string> > Pskillname(p);
    vector< vector<int> > Pskilllevel(p);
    for (int i = 0; i < p; i++)
    {
        string project;
        getline(fromfile, project);
        j = 0;
        while (project[j] != ' ')
        {
            Pname[i] += project[j];
            j++;
        }
        j++;
        while (project[j] != ' ')
        {
            j++;
        }
        j++;
        while (project[j] != ' ')
        {
            j++;
        }
        j++;
        while (project[j] != ' ')
        {
            j++;
        }
        j++;
        string o;
        while (j != project.size())
        {
            o += project[j];
            j++;
        }
        roles[i] = stoi(o);
        for (int k = 0; k < roles[i]; k++)
        {
            string Pskillandlevel;
            getline(fromfile, Pskillandlevel);
            j = 0;
            string s;
            while (Pskillandlevel[j] != ' ')
            {
                s += Pskillandlevel[j];
                j++;
            }
            Pskillname[i].push_back(s);
            string r;
            while (j != Pskillandlevel.size())
            {
                r += Pskillandlevel[j];
                j++;
            }
            Pskilllevel[i].push_back(stoi(r));
        }
    }

    //*********************************************************** Code for project assignment.****************************************************

    vector<pair<string,map<string, pair<string, int> > > > Projects;
    map<string, pair<string, int> > finalcontributers;
    int i=0;
    while(p!=0){
        for(int j=0; j<roles[i]; j++){
            checkpotentialcontibuter(Pskillname[i].at(j), Pskilllevel[i].at(j),finalcontributers, Contributers);
        }
        roles[i] -= finalcontributers.size();
        if(roles[i]==0){
            
            awardLevels(finalcontributers, Contributers);
            Projects.push_back(make_pair(Pname[i],finalcontributers));
            Pname.erase(Pname.begin()+i);
            Pname.erase(std::remove_if(Pname.begin(),Pname.end(),[](std::string const& s) { return s.size() != 0 && s.front() == ';'; }),Pname.end());
            
            roles.erase(roles.begin()+i);
            Pskilllevel.erase(Pskilllevel.begin()+i);
            Pskillname.erase(Pskillname.begin()+i);
            p--;
            i=0;
            finalcontributers.clear();
            continue;
        }
        int newroles=0;
        for(int j=0; j<roles[i]; j++){
            if(checkpotentialmentor(Pskillname[i].at(j), Pskilllevel[i].at(j), finalcontributers, Contributers)==true){
                newroles++;
            }
        }
        roles[i]-=newroles;
        if(roles[i]<=0){
            awardLevels(finalcontributers, Contributers);
            Projects.push_back(make_pair(Pname[i],finalcontributers));
            Pname.erase(Pname.begin()+i);
            Pname.erase(std::remove_if(Pname.begin(),Pname.end(),[](std::string const& s) { return s.size() != 0 && s.front() == ';'; }),Pname.end());
            roles.erase(roles.begin()+i);
            Pskilllevel.erase(Pskilllevel.begin()+i);
            Pskillname.erase(Pskillname.begin()+i);
            p--;
            i=0;
        }
        else
            i++;
        finalcontributers.clear();
    }
    ofstream tooutputfile("OutputFile.txt");
    tooutputfile<<Projects.size()<<endl;
    for(auto i : Projects){
        tooutputfile<<i.first<<endl;
        for(auto j: i.second){
            if(j.second.first=="None")
                tooutputfile<<j.first<<" : Mentored ; ";
            else
                tooutputfile<<j.first<<" : "<<j.second.first<<" ; ";
        }
        tooutputfile<<endl;
    }
    return 0;
}
