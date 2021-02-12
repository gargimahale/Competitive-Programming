#include <bits/stdc++.h>

using namespace std;

// Union find Data Structure

class Solution {
	struct Node{
		double value;
		Node* parent;
		Node(){
			parent=this;
		};
	};

	Node* find_parent(Node* x){
		if(x->parent==x) return x;
		return find_parent(x->parent);

	}

	void union_nodes(Node* a, Node* b, double num, unordered_map<string,Node*> table){
		Node* p1=find_parent(a);
		Node* p2=find_parent(b);
		double ratio=(b->value)*num/a->value;
		for(auto x:table){
			if(find_parent(x.second)==p1){
				x.second->value *=ratio;
			}
		}
		p1->parent=p2;
	}
public:
	//unordered_map<string,Node*> table;
	vector<double> res;
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		unordered_map<string,Node*> table;
		for(int i=0;i<equations.size();i++){
			if(table.find(equations[i][0])==table.end() && table.find(equations[i][1])==table.end()){
				table[equations[i][0]]=new Node();
				table[equations[i][1]]=new Node();
				table[equations[i][0]]->value=values[i];
				table[equations[i][1]]->value=1.0;
				table[equations[i][1]]->parent=table[equations[i][0]];


			}
			else if(table.find(equations[i][0])==table.end()){
				table[equations[i][0]]=new Node();
				table[equations[i][0]]->parent=table[equations[i][1]];
				table[equations[i][0]]->value=table[equations[i][1]]->value*values[i];
			}
			else if(table.find(equations[i][1])==table.end()){
				table[equations[i][1]]=new Node();
				table[equations[i][1]]->parent=table[equations[i][0]];
				table[equations[i][1]]->value=table[equations[i][0]]->value/values[i];
			}
			else{
				union_nodes(table[equations[i][0]],table[equations[i][1]],values[i], table);
			}

		}

		for(auto v:queries){
			if(table.find(v[0])!=table.end() && table.find(v[1])!=table.end() && find_parent(table[v[0]])==find_parent(table[v[1]])){
			   double newval=table[v[0]]->value/table[v[1]]->value;
			res.push_back(newval);

			}
			else{
			res.push_back(-1.0);
			}

		}

		return res;


	}
};



// OR -----------------------------------------------------------------------------------------------------------------------
// class Solution {
// public:
//     vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//         // a/b = 2, a = 2b,  b = a/2, a = 6c ,  c = a/6
//         // b/c= 3,  b = 3c,  c = b/3, b = a/2

//         // a/b = 2    b/c = 3
//         // b/a = 1/2  c/b = 1/3

//         // a/c = a/b * b/c = 2 * 3 = 6

//         // b/a = 1/2


//         // map[a] = 2.0*map[b]
//         // map[b] = map[a]/2.0
//         // map[b] = (map[a]/2.0)*map[c]*3.0
//         // map[c] = map[b]/3.0
//         // map[c] = (map[a]/2.0)*map[c]*3.0/3.0

//         // b/c = 3,
//         // (a/2)/c = 3
//         // (a/2)/(a/6) = c,
//         // C = 3, a = 6(3) = 18, a/c = 18/3 = 6, b = 3(3) = 9
//         // b/a = 9/18 = .5

//         //   b = 2b/2, b/2 = 2b,

//         vector<double> res(queries.size());
//         unordered_map<string, unordered_map<string, double>> graph;

//         // build map of normal and reverse division

//         for (int i = 0; i < equations.size(); i++ ){
//             vector<string> equation = equations[i];
//             graph[equation[0]][equation[1]] = values[i];
//             graph[equation[1]][equation[0]] = 1/values[i];
//         }

//         // Now, we need to try to arrive to the answer by looking at the graph

//         // probably union find
//         for (int i = 0; i < queries.size(); i++) {
//              vector<string> query = queries[i];
//             // a/c

//             // We want to look for a and then look at all the neighboors
//             // of a that might arrive at c.

//             if (graph.find(query[0]) == graph.end() ) {
//                 res[i] = -1.0;
//             }
//             else if (query[0] == query[1]) {
//                 res[i] = 1.0;
//             }
//             else {
//                 unordered_set<string> visited;
//                 res[i] = backtrackDfs(graph, query[0], query[1], 1, visited);
//             }
//         }

//         return res;
//     }

//     double backtrackDfs(unordered_map<string, unordered_map<string, double>>& graph, string start, string end, double runningProduct, unordered_set<string>& visited)
//     {
//         double result = -1.0;

//         // backtrack start
//         visited.insert(start);

//         if (graph.find(start) != graph.end()) {
//             // Check one by one,
//             // if the current item->second == query[1],
//             // then we found the solution
//             unordered_map<string, double> neighbors = graph[start];
//             // graph[a][b]=2
//             if (neighbors.find(end) != neighbors.end()) {
//                 // This means that we found a path from query[0] -> query[1].
//                 result = runningProduct * graph[start][end];
//             }
//             else {
//                 for (auto neighbor : neighbors) {

//                     if (visited.count(neighbor.first)) continue;

//                     result = backtrackDfs(
//                         graph,
//                         neighbor.first,
//                         end,
//                         runningProduct * neighbor.second,
//                         visited);

//                     if (result != -1.0) {
//                         break;
//                     }
//                 }
//             }
//         }

//         // backtrack end
//         visited.erase(start);

//         return result;
//     }
// };
