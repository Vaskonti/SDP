#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;


using Graph = unordered_map<int, list<int>>;

void fillGraph(Graph& a,list<int>& shouldVisit) {
    int numberOfNodes,node;
//    cout << "Please enter number of Nodes in the graph: ";
    cin >> numberOfNodes;
    for (int m = 0; m < numberOfNodes; m++)
    {
        cin >> node;
        a.insert({ node, std::list<int>() });
    }
    cout << "PLease enter how many connections: ";
    int connections;
    cin >> connections;
    string command;
    int firstNode,secondNode;

    for (int i = 0; i < connections; i++)
    {
        cin >> firstNode;
        cin >> command;
        cin >> secondNode;

        if (command == "<-->")
        {
            a[secondNode].push_back(firstNode);
        }
        else if (command == "<---")
        {
            a[firstNode].push_back(secondNode);
        }
        else if (command == "--->")
        {
            a[firstNode].push_back(secondNode);
            a[secondNode].push_back(firstNode);
        }
    }

    int numberOfCityToVis, nodeToVIs;
    cout << "Enter numbers of cities you want to visit: ";
    cin >> numberOfCityToVis;

    cout << "Please enter the cities' numbers: ";
    for (int j = 0; j < numberOfCityToVis; j++)
    {
        cin >> nodeToVIs;
        shouldVisit.push_back(nodeToVIs);
    }
}

bool containsThisCity(list<int>& path, int number) {
    auto iter = path.begin();
    for (iter; iter != path.end(); iter++)
    {
        if (*iter == number)
        {
            return true;
        }
    }
    return false;
}
void printPath(const list<int> & path) {

    for (const int city : path)
    {
        cout << city << ' ';
    }
    cout << '\n';
}
int getElementInPosition(list<int>& lst, int position) {
    if (position - 1 >= lst.size())
    {
        std::cout << "Wanting invalid position";
        return -1;
    }
    auto iter = lst.begin();
    for (int i = 0; i < position; i++)
    {
        iter++;
    }
    return *iter;

}
void shortestPathInGraph(Graph a, list<int> shouldVisit, list<int> currentPath, list<int>& shortestPath,int currentNumber) {
    if (a[currentNumber].empty()) // we have nowhere to go - end
    {
        if (shouldVisit.empty()) // still check cause this might be the shortest path
        {
            if (currentPath.size() < shortestPath.size())
            {
                shortestPath = currentPath;
            }
        }
    }
    else {

        currentPath.push_back(currentNumber);
        if (containsThisCity(shouldVisit,currentNumber))
        {
            shouldVisit.remove(currentNumber);
        }
        if (shouldVisit.empty())
        {
            if (shortestPath.size() > currentPath.size())
            {
                shortestPath = currentPath;
                return;
            }
        }

        for (const int successor : a[currentNumber])
        {
            int currentPathSize = currentPath.size();
            if (a[currentNumber].size() > 1 && getElementInPosition(currentPath,currentPathSize - 2) != successor)
            {
                shortestPathInGraph(a,shouldVisit,currentPath,shortestPath,successor);
            }
        }
    }
}

bool shortestPath( Graph & graph, list<int> & shouldVisit) {
    list<int> currentPath;
    list<int> shortestPath (graph.size() * 2,0);
    shortestPathInGraph(graph, shouldVisit, currentPath, shortestPath, shouldVisit.front());
    // should have a size of shortest path(at first should be the longest) to compare it with / could use MAX_INT but idk
    if (shortestPath.size() < graph.size() * 2)
    {
        printPath(shortestPath);
        return true;
    }
    else {
        throw std::logic_error("No such path found!");
    }
}

int main() {
    Graph myGraph;
    list<int> citiesToVisit;
    fillGraph(myGraph, citiesToVisit);
    bool foundIt = shortestPath(myGraph, citiesToVisit);
    if (foundIt)
    {
        std::cout << "yes\n";
    }
    else {
        cout << "No\n";
    }
    return 0;
}
