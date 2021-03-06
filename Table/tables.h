#include "variant.hpp"
//union UN{
//	char cfun;
//	int ifun;
//};
struct keyStr// ������� ������� ������ // key part of table element
{
	Key_1 str;	 // ������ ���� // key fields
		//---!!!��������� �� ��������!!!---
	Key_2 nMod;//---!!!to define by variant!!!---
};
// ---!!!�����: ���� ����, ��������� ������������: enum|struct|union!!!---
// ---!!!������� ���� ��'������ ���������� � ����� ����!!!---
// ---!!!Attention: user defined field types: enum|struct|union!!!---
// ---!!!should be declared at this place!!!---
	// ����������� ��� ��� ��������������� ���� �� ��������
/* union c65	// special type for functional field by variant
 {unsigned addr;
 unsigned length;};*/
 // ������������� ������� ������
struct fStr	// functional part of record
{//f-���� ---!!!��������� �� ��������!!!---
	FunctionalField _f;//f-field ---!!!to define by variant!!!---
};
struct recrd// ��������� ����� �������
{			// �������� ��������� �����
	struct keyStr key;	// instantiation of key structure
			   // �������� ������������� �������
	struct fStr func;	// instantiation of functional part
			   // ������ ��������� 
	char _del;	// mark of deleted record
};
#define ASM 0	// ��� ������� �� ��������, ���� 0
// when 0 - without Assembler insertions
//------------------------------------------------------
// ������� ������ ������� �� ������ �������
// ---!!!�����: ���� ���� � ���������� int nElm ������� ���� ������� !!!---
// table record processing by direct address
// ---!!!Attention: field types in arguments int nElm should be replaced !!!---
// ������ �� ������ �������
// retreaving by direct address
struct recrd* selNmb(struct recrd*, unsigned int nElm);
// ��������� �� ������ �������
// insertion by direct address
struct recrd* insNmb(struct recrd*pElm,
	struct recrd*tb, unsigned int nElm, int*pQnElm);
// ��������� �� ������ �������
// deleting by direct address
struct recrd* delNmb(struct recrd*, unsigned int nElm);
// �������� �� ������ �������
// correction by direct address
struct recrd* updNmb(struct recrd*pElm,
	struct recrd*tb, unsigned int nElm, int*pQnElm);
//------------------------------------------------------
// ��������� �� ���������� ��������
// comparison by nonequlity relation
int neqKey(struct recrd*, struct keyStr);
// ��������� �����
// row comparison 
int cmpStr(unsigned int* s1, unsigned int* s2);
// ��������� �� ���������� ������� �����
// comparison by order relation for rows
int cmpKey(struct recrd*, struct keyStr);
// ��������� �� ���������� ������� ��� ������
// comparison by order relation for keys
int cmpKys(struct keyStr*, struct keyStr*);
// ��������� �� ���������� �������
// comparison by similarity relation 
int simKey(struct recrd*, struct keyStr);
//------------------------------------------------------
// ������ �� ������� �������
// retreaving by linear search
struct recrd*selLin(struct keyStr, struct recrd*tb, int ln);
// �������� ������ �� ������� �������
// next retreaving by linear search
struct recrd* selLinNxt(struct keyStr kArg,
	struct recrd* tb, int ln);
// ��������� �� ������� �������
// insertion by linear search
struct recrd*insLin(struct recrd*pElm,
	struct recrd*tb, int*pQnElm);
// ��������� �� ������� �������
// deleting by linear search
struct recrd*delLin(struct recrd*pElm,
	struct recrd*tb, int*pQnElm);
// �������� �� ������� �������
// correction by linear search
struct recrd*updLin(struct keyStr, struct recrd*pElm,
	struct recrd*tb, int*pQnElm);
// ��������� ��� �������� ������
// packing for linear search
struct recrd*pckLin(struct recrd*tb, int*pQnElm);
//------------------------------------------------------
// ���������� �� �������� �������
// sorting for linear search
struct recrd*srtBin(struct recrd*, int ln);
// ������ �� �������� �������
// retreaving by binary search
struct recrd*selBin(struct keyStr, struct recrd*, int ln);
//---!!! ��������� ����������� �� ��������!!!---
// ��������� �� �������� �������
// insertion by binary search
struct recrd*insBin(struct recrd*pElm,
	struct recrd*tb, int*pQnElm);
// ��������� �� �������� �������
// deleting by binary search
struct recrd*delBin(struct recrd*pElm,
	struct recrd*tb, int*pQnElm);
// �������� �� �������� �������
// correction by binary search
struct recrd*updBin(struct keyStr, struct recrd*pElm,
	struct recrd*tb, int*pQnElm);

//New functions of mine:

//Counts the number of letters present in both  
unsigned int coincSymbs(const char *pLeft, const char *pRight);
unsigned int coincSymbs(struct recrd*pLeft, struct recrd*pRight);