#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/IR/GlobalValue.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/ValueSymbolTable.h"

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
        bool isDecl = i->isDeclaration();
        if(isDecl) {
          continue;
        }
        errs() << "F: " << i->getName() <<
          " is decl: " << i->isDeclaration() <<
          " has L: " << i->getLinkage() <<
          " has T: " << i->getType()->getElementType()->getTypeID() <<
          "\n";

         // To get more information about a function or global
         // variable we can store that information under a named
         // metadata node with the name of that function or variable
         // Module::getNamedMetadata to get it.
         // Module::getOrInsertNamedMetadata to make it.
         // the metadata can have additional information like unmangled
         // name, namespace or class, etc.
         //
         // We also want to expose types that the module defines.
         // for this we could just have a single named metadata 'types'
         // that has all type information.
         //
         // Sadly it seems as though clang is not as modular as llvm is
         // and adding this functionality requires modifying clang to
         // emit this information, rather than defining a plugin.
	 //
         // This module would then read the metadata, and emit a section
	 // 
         // I think the section would be in IR, and then the codegen would
         // pick it up as a IR and transform it to MC, which then would
         // be compiled to a specific format.
	 //
	 // We can get data into a specific section by defining a global
         // variable and setting its section attribute.
         //
         // Shorter plan: Just modify clang to collect all metadata and
         // emit it to a global variable with a section attribute. No
         // need for this module pass.
      }

      iplist<GlobalVariable>& vars = M.getGlobalList();

      iplist<GlobalVariable>::iterator j;
      for(j = vars.begin(); j != vars.end(); j++)
      {
        bool isDecl = j->isDeclaration();
        if(isDecl) {
          continue;
        }
        errs() << "V: " << j->getName() <<
          " is decl: " << j->isDeclaration() <<
          " has L: " << j->getLinkage() <<
          " has T: " << j->getType()->getElementType()->getTypeID() <<
          "\n";
      }

      // Build a tree of namespaces, the first being the global namespace
      // which is the default for C.

      return false;
    }
  };
}

char TypeSection::ID = 0;

static RegisterPass<TypeSection> X("type-section", "Type Section Pass",
                  false, false);
