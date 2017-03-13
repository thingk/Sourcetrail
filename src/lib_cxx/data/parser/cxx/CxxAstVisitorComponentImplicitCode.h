#ifndef CXX_AST_VISITOR_COMPONENT_IMPLICIT_CODE_H
#define CXX_AST_VISITOR_COMPONENT_IMPLICIT_CODE_H

#include "data/parser/cxx/CxxAstVisitorComponent.h"
#include "data/parser/cxx/CxxContext.h"

// This CxxAstVisitorComponent is responsible for deciding if the AstVisitor should visit implicit code in the current context.
class CxxAstVisitorComponentImplicitCode: public CxxAstVisitorComponent
{
public:
	CxxAstVisitorComponentImplicitCode(CxxAstVisitor* astVisitor);
	virtual ~CxxAstVisitorComponentImplicitCode();

	bool shouldVisitImplicitCode() const;

	virtual void beginTraverseDecl(clang::Decl* d);
	virtual void endTraverseDecl(clang::Decl* d);

	virtual void beginTraverseCXXForRangeStmt(clang::CXXForRangeStmt* s);
	virtual void endTraverseCXXForRangeStmt(clang::CXXForRangeStmt* s);

private:
	std::vector<bool> m_stack;
};

#endif // CXX_AST_VISITOR_COMPONENT_IMPLICIT_CODE_H