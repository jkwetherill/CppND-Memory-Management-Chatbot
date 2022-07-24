#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
    //_chatBot = nullptr;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
    //if (_chatBot != nullptr)
        //delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge>&& edge) //GraphEdge *edge)
{
    _childEdges.push_back(std::move(edge));
}

/*
void GraphNode::AddEdgeToChildNode(GraphEdge*&& edge)
{
    _childEdges.push_back(edge);
}
*/
//// STUDENT CODE
////

// void GraphNode::MoveChatbotHere(ChatBot *chatbot)
// void GraphNode::MoveChatbotHere(std::unique_ptr<ChatBot>&& chatbot)

/*
void GraphNode::MoveChatbotHere(ChatBot&& chatbot)
{
    //_chatBot = std::move(chatbot);
    _chatBot.reset(&chatbot);
    _chatBot->SetCurrentNode(this);
}
*/

void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
   // _chatBot.reset(&chatbot);
   // _chatBot->SetCurrentNode(this);

    //_chatBot = std::move(chatbot);
    //_chatBot.SetCurrentNode(this);



    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{

    // newNode->MoveChatbotHere(std::move(_chatBot));
    // newNode->MoveChatbotHere(std::move(*_chatBot.get()));

    //ChatBot NewChatBot = ChatBot("../images/chatbot.png");
    ChatBot NewChatBot2{std::move(_chatBot)};
    //ChatBot&& NewChatBotRef = std::move(_chatBot);
    //newNode->MoveChatbotHere(std::move(NewChatBot2));
    newNode->MoveChatbotHere(NewChatBot2);

    //_chatBot = nullptr; // invalidate pointer at source
    //_chatBot = nullptr;
    //_chatBot.~ChatBot();
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
//std::unique_ptr<GraphEdge>& GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}