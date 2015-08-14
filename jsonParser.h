//---------------------first gitProject ......:just try Edit code in webBrowser.
#include "dataStruct.h"
//------------------------macro---------------------------------//
#define TRUE 1
#define FALSE 0

#define jDebugP(str,...) do{ printf("[%s_%d:%s]"#str"\n",__FILE__,__LINE__,__FUNC__,##_VA_ARGS__);}while(0)
//-------------------------typedef------------------------------//
typedef enum _jItemType_E{
false =1>>1;
true  =1<<0;
null  =1<<1;
int   =1<<2;
string=1<<3;
array =1<<4;
object=1<<5;
aParent=1<<6;
oParent=1<<7;//bit[6,7]==0->onRoot.
empty =~0;
}jItemType_E;

typedef List_T jList_T;
typedef Node_T jNode_T;
typedef struct _jItem_T{
  int type;
  union{
  int int_t;
  char *string;
  jList_T *array;
  jList_T *object;
  }data;
  char *index;
  char end[0];
}jItem_T;

typedef enum _errorCode_E{
CONTINUEPARSE = 1>>1;
ILLEGALCHAR   = 1>>0;

FINISHPARSE   =~0;
}errorCode_E;

//
extern void jParse(const char *string,int length,jMsgcntl_T *msg);
extern void jBooleanParse();
extern void jNullParse();
extern void jNumberParse();
extern void jArrayParse();
extern void JObjectParse();

//----------util&test---------
extern void jParserPrinter(JList_T *json);
extern char* jFactory(JList_T *jlist);
extern void jCreater(JList_T *jlist);
extern void jAddItem(jList_T *parent,JNode_T *child);

