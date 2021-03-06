#include <iostream>
 
#define LH  1 // 左子树高
#define EH  0 // 等高
#define RH  -1// 右子树高
 
using namespace std;
 
struct AVLTreeNode
{
    int             m_nValue;   // 值
    int             m_nBf;      // 平衡因子
    AVLTreeNode*    m_pLeft;    // 左孩子
    AVLTreeNode*    m_pRight;   // 右孩子
};
 
// 平衡操作
void RightRotation(AVLTreeNode*& pRoot);
void LeftRotation(AVLTreeNode*& pRoot);
void LeftBanlance(AVLTreeNode*& pRoot);
void RightBanlance(AVLTreeNode*& pRoot);
 
// 常规操作
bool InsertAVL(AVLTreeNode*& pRoot, int value, bool &taller);
 
int main()
{
    ios::sync_with_stdio(false);
    // 建树
    AVLTreeNode* pRoot = NULL;
    bool taller = false;
    int value, N; cin >> N;
    for(int i=0; i<N; i++) {
        cin >> value;
        InsertAVL(pRoot, value, taller);
    }
 
    cout << pRoot->m_nValue << endl;
 
    return 0;
}
 
// 新结点插入成功，则返回true
// taller反映树是否长高
bool InsertAVL(AVLTreeNode*& pRoot, int value, bool &taller)
{
    if(!pRoot)  // 走到NULL处插入新节点
    {
        pRoot = new AVLTreeNode();
        pRoot->m_nBf = EH;
        pRoot->m_nValue = value;
        pRoot->m_pLeft = pRoot->m_pRight = NULL;
        taller = true;
    }
    else
    {
        if(value == pRoot->m_nValue) // 走到此步，说明要插入的节点已存在，返回false
        {
            taller = false;
            return false;
        }
        if(value < pRoot->m_nValue) //继续在pRoot的左子树中搜索插入位置
        {
            if(!InsertAVL(pRoot->m_pLeft, value, taller)) // 插入失败
                return false;
            if(taller) // 已插入pRoot的左子树,且左子树长高
            {
                switch(pRoot->m_nBf)
                {
                case LH: // 原本左侧就高，还插在了左侧，作左部平衡
                    LeftBanlance(pRoot);
                    taller = false;     // 平衡处理后树高不变
                    break;
                case EH: // 原本等高，插在左侧，树增高
                    pRoot->m_nBf = LH;
                    taller = true;
                    break;
                case RH: // 原本右侧高，插在左侧，树高不变
                    pRoot->m_nBf = EH;
                    taller = false;
                    break;
                }
            }
        }
        else    //继续在pRoot的右子树中搜索插入位置
        {
            if(!InsertAVL(pRoot->m_pRight, value, taller)) // 插入失败
                return false;
            if(taller) // 已插入pRoot的右子树,且右子树长高
            {
                switch(pRoot->m_nBf)
                {
                case LH: // 原本左侧高，插在右侧，树高不变
                    pRoot->m_nBf = EH;
                    taller = false;
                    break;
                case EH: // 原本等高，插在右侧，树增高
                    pRoot->m_nBf = RH;
                    taller = true;
                    break;
                case RH: // 原本右侧就高，还插在了右侧，作右部平衡
                    RightBanlance(pRoot);
                    taller = false;
                    break;
                }
            }
        }
    }
    return true;
}
 
// 左旋，以pRoot为根节点的树进行左旋处理,并调整好了父子链接
void LeftRotation(AVLTreeNode*& pRoot)
{
    // pRoot现为左上失衡节点, pRight为pRoot的右子结点， pRoot、pRight进行左旋转
    AVLTreeNode* pRight = pRoot->m_pRight;
 
    pRoot->m_pRight = pRight->m_pLeft;
    pRight->m_pLeft = pRoot;
 
    pRoot = pRight;
}
 
// 右旋，以pRoot为根节点的树进行右旋处理,并调整好了父子链接
void RightRotation(AVLTreeNode*& pRoot)
{
    // pRoot现为失衡节点, pLeft为pRoot的左子结点， pLeft、pRoot进行右旋转
    AVLTreeNode* pLeft = pRoot->m_pLeft;
 
    pRoot->m_pLeft = pLeft->m_pRight;
    pLeft->m_pRight = pRoot;
 
    pRoot = pLeft;
}
 
// 左部失重平衡处理，处理LL、LR
//以pRoot为根节点的树进行左平衡旋转处理
void LeftBanlance(AVLTreeNode*& pRoot)
{
    AVLTreeNode* pLeft, *pLeftRight;
    pLeft = pRoot->m_pLeft;
    switch(pLeft->m_nBf)
    {
    case LH:    // LL型
        pRoot->m_nBf = EH;
        pLeft->m_nBf = EH;
        RightRotation(pRoot);
        break;
    case RH:    // LR型
        pLeftRight = pLeft->m_pRight;
        switch(pLeftRight->m_nBf)
        {
        case LH:
            pRoot->m_nBf = RH;
            pLeft->m_nBf = EH;
            break;
        case EH:
           pRoot->m_nBf = EH;
           pLeft->m_nBf = EH;
            break;
        case RH:
            pRoot->m_nBf = EH;
            pLeft->m_nBf = LH;
            break;
        }
        pLeftRight->m_nBf = EH;
        LeftRotation(pRoot->m_pLeft); //这里pRoot->m_pLeft不能写成pLeft，否则关系没调整
        RightRotation(pRoot);
        break;
    }
}
 
// 右部失重平衡处理，处理RL、RR
//以pRoot为根节点的树进行右平衡旋转处理
void RightBanlance(AVLTreeNode*& pRoot)
{
    AVLTreeNode* pRight, *pRightLeft;
    pRight = pRoot->m_pRight;
    switch(pRight->m_nBf)
    {
    case RH:    // RR型
        pRoot->m_nBf = pRight->m_nBf = EH;
        LeftRotation(pRoot);
        break;
    case LH:    // RL型
        pRightLeft = pRight->m_pLeft;
        switch(pRightLeft->m_nBf)
        {
        case LH:
            pRoot->m_nBf = EH;
            pRight->m_nBf = RH;
            break;
        case EH:
           pRoot->m_nBf = EH;
            pRight->m_nBf = EH;
            break;
        case RH:
            pRoot->m_nBf = LH;
            pRight->m_nBf = EH;
            break;
        }
        pRightLeft->m_nBf = EH;
        RightRotation(pRoot->m_pRight); //这里pRoot->m_pRight不能写成pRight，否则关系没调整
        LeftRotation(pRoot);
        break;
    }
}