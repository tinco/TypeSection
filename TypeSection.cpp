#include "llvm/Pass.h"
#include "llvm/Module.h"
#include "llvm/Function.h"
#include "llvm/GlobalVariable.h"
#include "llvm/GlobalValue.h"
#include "llvm/DerivedTypes.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/ValueSymbolTable.h"

using namespace llvm;

namespace {
  struct TypeSection : public ModulePass {
    static char ID;
    TypeSection() : ModulePass(ID) {}

    virtual bool runOnModule(Module &M) {
      iplist<Function>& functions = M.getFunctionList();

      iplist<Function>::iterator i;
      for(i = functions.begin(); i != functions.end(); i++)
      {
        errs() << "F: " << i->getName() <<
          " is decl: " << i->isDeclaration() <<
          " has L: " << i->getLinkage() <<
          " has T: " << i->getType()->getElementType()->getTypeID() <<
          "\n";
      }

      iplist<GlobalVariable>& vars = M.getGlobalList();

      iplist<GlobalVariable>::iterator j;
      for(j = vars.begin(); j != vars.end(); j++)
      {
        errs() << "V: " << j->getName() <<
          " is decl: " << j->isDeclaration() <<
          " has L: " << j->getLinkage() <<
          " has T: " << j->getType()->getElementType()->getTypeID() <<
          "\n";
      }

      return false;
    }
  };
}

char TypeSection::ID = 0;

static RegisterPass<TypeSection> X("type-section", "Type Section Pass",
                  false, false);
