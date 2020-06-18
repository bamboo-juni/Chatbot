#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// TASK 0: DONE
    ////

    //delete _chatBot; 

    ////
    //// EOF TASK 0
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) // TASK 4
{
    _childEdges.push_back(std::move(edge));
}

//// TASK 5: DONE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
    //_chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF TASK 5

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// TASK 4: DONE
    ////

    return _childEdges[index].get();

    ////
    //// EOF TASK 4
}