#pragma once
#if defined(__i386__) || defined(_M_IX86)

#if !defined(_MSC_VER) && !defined(_Printf_format_string_)
#define _Printf_format_string_
#endif

class CCodeBlock;

class CX86Ops
{
public:
    enum x86Reg
    {
        x86_EAX = 0,
        x86_EBX = 3,
        x86_ECX = 1,
        x86_EDX = 2,
        x86_ESI = 6,
        x86_EDI = 7,
        x86_EBP = 5,
        x86_ESP = 4,
        x86_Unknown = -1,

        x86_AL = 0,
        x86_BL = 3,
        x86_CL = 1,
        x86_DL = 2,
        x86_AH = 4,
        x86_BH = 7,
        x86_CH = 5,
        x86_DH = 6
    };

    enum x86FpuValues
    {
        x86_ST_Unknown = -1,
        x86_ST0 = 0,
        x86_ST1 = 1,
        x86_ST2 = 2,
        x86_ST3 = 3,
        x86_ST4 = 4,
        x86_ST5 = 5,
        x86_ST6 = 6,
        x86_ST7 = 7
    };

    enum Multipler
    {
        Multip_x1 = 1,
        Multip_x2 = 2,
        Multip_x4 = 4,
        Multip_x8 = 8
    };

    static const char * x86_Name(x86Reg Reg);
    static const char * x86_ByteName(x86Reg Reg);
    static const char * x86_HalfName(x86Reg Reg);
    static const char * fpu_Name(x86FpuValues Reg);

    CX86Ops(CCodeBlock & CodeBlock);

    // Logging functions
    void WriteX86Comment(const char * Comment);
    void WriteX86Label(const char * Label);

    void AdcX86regToVariable(x86Reg reg, void * Variable, const char * VariableName);
    void AdcConstToVariable(void * Variable, const char * VariableName, uint8_t Constant);
    void AdcConstToX86Reg(x86Reg Reg, uint32_t Const);
    void AdcVariableToX86reg(x86Reg reg, void * Variable, const char * VariableName);
    void AdcX86RegToX86Reg(x86Reg Destination, x86Reg Source);
    void AddConstToVariable(uint32_t Const, void * Variable, const char * VariableName);
    void AddConstToX86Reg(x86Reg Reg, uint32_t Const, bool NeedCarry = false);
    void AddVariableToX86reg(x86Reg reg, void * Variable, const char * VariableName);
    void AddX86regToVariable(x86Reg reg, void * Variable, const char * VariableName);
    void AddX86RegToX86Reg(x86Reg Destination, x86Reg Source);
    void AndConstToVariable(uint32_t Const, void * Variable, const char * VariableName);
    void AndConstToX86Reg(x86Reg Reg, uint32_t Const);
    void AndVariableToX86Reg(void * Variable, const char * VariableName, x86Reg Reg);
    void AndVariableDispToX86Reg(void * Variable, const char * VariableName, x86Reg Reg, x86Reg AddrReg, Multipler Multiply);
    void AndX86RegToX86Reg(x86Reg Destination, x86Reg Source);
    void X86HardBreakPoint();
    void X86BreakPoint(const char * FileName, int32_t LineNumber);
    void CallFunc(uint32_t FunctPtr, const char * FunctName);
    void CallThis(uint32_t ThisPtr, uint32_t FunctPtr, char * FunctName, uint32_t StackSize);
    void CompConstToVariable(uint32_t Const, void * Variable, const char * VariableName);
    void CompConstToX86reg(x86Reg Reg, uint32_t Const);
    void CompConstToX86regPointer(x86Reg Reg, uint32_t Const);
    void CompX86regToVariable(x86Reg Reg, void * Variable, const char * VariableName);
    void CompVariableToX86reg(x86Reg Reg, void * Variable, const char * VariableName);
    void CompX86RegToX86Reg(x86Reg Destination, x86Reg Source);
    void DecX86reg(x86Reg Reg);
    void DivX86reg(x86Reg reg);
    void idivX86reg(x86Reg reg);
    void imulX86reg(x86Reg reg);
    void IncX86reg(x86Reg Reg);
    void JaeLabel8(const char * Label, uint8_t Value);
    void JaeLabel32(const char * Label, uint32_t Value);
    void JaLabel8(const char * Label, uint8_t Value);
    void JaLabel32(const char * Label, uint32_t Value);
    void JbLabel8(const char * Label, uint8_t Value);
    void JbLabel32(const char * Label, uint32_t Value);
    void JecxzLabel8(const char * Label, uint8_t Value);
    void JeLabel8(const char * Label, uint8_t Value);
    void JeLabel32(const char * Label, uint32_t Value);
    void JgeLabel8(const char * Label, uint8_t Value);
    void JgeLabel32(const char * Label, uint32_t Value);
    void JgLabel8(const char * Label, uint8_t Value);
    void JgLabel32(const char * Label, uint32_t Value);
    void JleLabel8(const char * Label, uint8_t Value);
    void JleLabel32(const char * Label, uint32_t Value);
    void JlLabel8(const char * Label, uint8_t Value);
    void JlLabel32(const char * Label, uint32_t Value);
    void JmpDirectReg(x86Reg reg);
    void JmpIndirectLabel32(const char * Label, uint32_t location);
    void JmpIndirectReg(x86Reg reg);
    void JmpLabel8(const char * Label, uint8_t Value);
    void JmpLabel32(const char * Label, uint32_t Value);
    void JneLabel8(const char * Label, uint8_t Value);
    void JneLabel32(const char * Label, uint32_t Value);
    void JnsLabel8(const char * Label, uint8_t Value);
    void JnsLabel32(const char * Label, uint32_t Value);
    void JnzLabel8(const char * Label, uint8_t Value);
    void JnzLabel32(const char * Label, uint32_t Value);
    void JoLabel32(const char * Label, uint32_t Value);
    void JsLabel32(const char * Label, uint32_t Value);
    void JzLabel8(const char * Label, uint8_t Value);
    void JzLabel32(const char * Label, uint32_t Value);
    void LeaRegReg(x86Reg RegDest, x86Reg RegSrc, uint32_t Const, Multipler multiplier);
    void LeaRegReg2(x86Reg RegDest, x86Reg RegSrc, x86Reg RegSrc2, Multipler multiplier);
    void LeaSourceAndOffset(x86Reg x86DestReg, x86Reg x86SourceReg, int32_t offset);
    void MoveConstByteToN64Mem(uint8_t Const, x86Reg AddrReg);
    void MoveConstHalfToN64Mem(uint16_t Const, x86Reg AddrReg);
    void MoveConstByteToVariable(uint8_t Const, void * Variable, const char * VariableName);
    void MoveConstByteToX86regPointer(uint8_t Const, x86Reg AddrReg1, x86Reg AddrReg2);
    void MoveConstHalfToVariable(uint16_t Const, void * Variable, const char * VariableName);
    void MoveConstHalfToX86regPointer(uint16_t Const, x86Reg AddrReg1, x86Reg AddrReg2);
    void MoveConstToMemoryDisp(uint32_t Const, x86Reg AddrReg, uint32_t Disp);
    void MoveConstToN64Mem(uint32_t Const, x86Reg AddrReg);
    void MoveConstToN64MemDisp(uint32_t Const, x86Reg AddrReg, uint8_t Disp);
    void MoveConstToVariable(uint32_t Const, void * Variable, const char * VariableName);
    void MoveConstToX86Pointer(uint32_t Const, x86Reg X86Pointer);
    void MoveConstToX86reg(uint32_t Const, x86Reg reg);
    void MoveConstToX86regPointer(uint32_t Const, x86Reg AddrReg1, x86Reg AddrReg2);
    void MoveN64MemDispToX86reg(x86Reg reg, x86Reg AddrReg, uint8_t Disp);
    void MoveN64MemToX86reg(x86Reg reg, x86Reg AddrReg);
    void MoveN64MemToX86regByte(x86Reg reg, x86Reg AddrReg);
    void MoveN64MemToX86regHalf(x86Reg reg, x86Reg AddrReg);
    void MoveSxByteX86regPointerToX86reg(x86Reg AddrReg1, x86Reg AddrReg2, x86Reg reg);
    void MoveSxHalfX86regPointerToX86reg(x86Reg AddrReg1, x86Reg AddrReg2, x86Reg reg);
    void MoveSxN64MemToX86regByte(x86Reg reg, x86Reg AddrReg);
    void MoveSxN64MemToX86regHalf(x86Reg reg, x86Reg AddrReg);
    void MoveSxVariableToX86regByte(void * Variable, const char * VariableName, x86Reg reg);
    void MoveSxVariableToX86regHalf(void * Variable, const char * VariableName, x86Reg reg);
    void MoveVariableDispToX86Reg(void * Variable, const char * VariableName, x86Reg Reg, x86Reg AddrReg, int32_t Multiplier);
    void MoveVariableToX86reg(void * Variable, const char * VariableName, x86Reg reg);
    void MoveVariableToX86regByte(void * Variable, const char * VariableName, x86Reg reg);
    void MoveVariableToX86regHalf(void * Variable, const char * VariableName, x86Reg reg);
    void MoveX86PointerToX86reg(x86Reg reg, x86Reg X86Pointer);
    void MoveX86PointerToX86regDisp(x86Reg reg, x86Reg X86Pointer, uint8_t Disp);
    void MoveX86regByteToN64Mem(x86Reg reg, x86Reg AddrReg);
    void MoveX86regByteToVariable(x86Reg reg, void * Variable, const char * VariableName);
    void MoveX86regByteToX86regPointer(x86Reg reg, x86Reg AddrReg1, x86Reg AddrReg2);
    void MoveX86regHalfToN64Mem(x86Reg reg, x86Reg AddrReg);
    void MoveX86regHalfToVariable(x86Reg reg, void * Variable, const char * VariableName);
    void MoveX86regHalfToX86regPointer(x86Reg reg, x86Reg AddrReg1, x86Reg AddrReg2);
    void MoveX86regPointerToX86reg(x86Reg AddrReg1, x86Reg AddrReg2, x86Reg reg);
    void MoveX86regPointerToX86regDisp8(x86Reg AddrReg1, x86Reg AddrReg2, x86Reg reg, uint8_t offset);
    void MoveX86regToMemory(x86Reg reg, x86Reg AddrReg, uint32_t Disp);
    void MoveX86regToN64Mem(x86Reg reg, x86Reg AddrReg);
    void MoveX86regToN64MemDisp(x86Reg reg, x86Reg AddrReg, uint8_t Disp);
    void MoveX86regToVariable(x86Reg reg, void * Variable, const char * VariableName);
    void MoveX86RegToX86Reg(x86Reg Source, x86Reg Destination);
    void MoveX86regToX86Pointer(x86Reg reg, x86Reg X86Pointer);
    void MoveX86regToX86regPointer(x86Reg reg, x86Reg AddrReg1, x86Reg AddrReg2);
    void MoveZxByteX86regPointerToX86reg(x86Reg AddrReg1, x86Reg AddrReg2, x86Reg reg);
    void MoveZxHalfX86regPointerToX86reg(x86Reg AddrReg1, x86Reg AddrReg2, x86Reg reg);
    void MoveZxN64MemToX86regByte(x86Reg reg, x86Reg AddrReg);
    void MoveZxN64MemToX86regHalf(x86Reg reg, x86Reg AddrReg);
    void MoveZxVariableToX86regByte(void * Variable, const char * VariableName, x86Reg reg);
    void MoveZxVariableToX86regHalf(void * Variable, const char * VariableName, x86Reg reg);
    void MulX86reg(x86Reg reg);
    void NotX86Reg(x86Reg Reg);
    void OrConstToVariable(uint32_t Const, void * Variable, const char * VariableName);
    void OrConstToX86Reg(uint32_t Const, x86Reg reg);
    void OrVariableToX86Reg(void * Variable, const char * VariableName, x86Reg Reg);
    void OrX86RegToVariable(void * Variable, const char * VariableName, x86Reg Reg);
    void OrX86RegToX86Reg(x86Reg Destination, x86Reg Source);
    void Push(x86Reg reg);
    void Pushad();
    void PushImm32(uint32_t Value);
    void PushImm32(const char * String, uint32_t Value);
    void Pop(x86Reg reg);
    void Popad();
    void Ret();
    void Seta(x86Reg reg);
    void Setae(x86Reg reg);
    void SetaVariable(void * Variable, const char * VariableName);
    void Setb(x86Reg reg);
    void SetbVariable(void * Variable, const char * VariableName);
    void Setg(x86Reg reg);
    void SetgVariable(void * Variable, const char * VariableName);
    void Setl(x86Reg reg);
    void SetlVariable(void * Variable, const char * VariableName);
    void Setz(x86Reg reg);
    void Setnz(x86Reg reg);
    void ShiftLeftDouble(x86Reg Destination, x86Reg Source);
    void ShiftLeftDoubleImmed(x86Reg Destination, x86Reg Source, uint8_t Immediate);
    void ShiftLeftSign(x86Reg reg);
    void ShiftLeftSignImmed(x86Reg reg, uint8_t Immediate);
    void ShiftRightDouble(x86Reg Destination, x86Reg Source);
    void ShiftRightDoubleImmed(x86Reg Destination, x86Reg Source, uint8_t Immediate);
    void ShiftRightSign(x86Reg reg);
    void ShiftRightSignImmed(x86Reg reg, uint8_t Immediate);
    void ShiftRightUnsign(x86Reg reg);
    void ShiftRightUnsignImmed(x86Reg reg, uint8_t Immediate);
    void SbbConstFromX86Reg(x86Reg Reg, uint32_t Const);
    void SbbVariableFromX86reg(x86Reg reg, void * Variable, const char * VariableName);
    void SbbX86RegToX86Reg(x86Reg Destination, x86Reg Source);
    void SubConstFromVariable(uint32_t Const, void * Variable, const char * VariableName);
    void SubConstFromX86Reg(x86Reg Reg, uint32_t Const);
    void SubVariableFromX86reg(x86Reg reg, void * Variable, const char * VariableName);
    void SubX86RegToX86Reg(x86Reg Destination, x86Reg Source);
    void TestConstToX86Reg(uint32_t Const, x86Reg reg);
    void TestVariable(uint32_t Const, void * Variable, const char * VariableName);
    void TestX86RegToX86Reg(x86Reg Destination, x86Reg Source);
    void TestX86ByteRegToX86Reg(x86Reg Destination, x86Reg Source);
    void XorConstToX86Reg(x86Reg Reg, uint32_t Const);
    void XorX86RegToX86Reg(x86Reg Source, x86Reg Destination);
    void XorVariableToX86reg(void * Variable, const char * VariableName, x86Reg reg);

    void fpuAbs();
    void fpuAddDword(void * Variable, const char * VariableName);
    void fpuAddDwordRegPointer(x86Reg x86Pointer);
    void fpuAddQword(void * Variable, const char * VariableName);
    void fpuAddQwordRegPointer(x86Reg X86Pointer);
    void fpuAddReg(x86FpuValues reg);
    void fpuAddRegPop(int32_t & StackPos, x86FpuValues reg);
    void fpuComDword(void * Variable, const char * VariableName, bool Pop);
    void fpuComDwordRegPointer(x86Reg X86Pointer, bool Pop);
    void fpuComQword(void * Variable, const char * VariableName, bool Pop);
    void fpuComQwordRegPointer(x86Reg X86Pointer, bool Pop);
    void fpuComReg(x86FpuValues reg, bool Pop);
    void fpuDivDword(void * Variable, const char * VariableName);
    void fpuDivDwordRegPointer(x86Reg X86Pointer);
    void fpuDivQword(void * Variable, const char * VariableName);
    void fpuDivQwordRegPointer(x86Reg X86Pointer);
    void fpuDivReg(x86FpuValues Reg);
    void fpuDivRegPop(x86FpuValues reg);
    void fpuExchange(x86FpuValues Reg);
    void fpuFree(x86FpuValues Reg);
    void fpuDecStack(int32_t & StackPos);
    void fpuIncStack(int32_t & StackPos);
    void fpuLoadControl(void * Variable, const char * VariableName);
    void fpuLoadDword(int32_t & StackPos, void * Variable, const char * VariableName);
    void fpuLoadDwordFromX86Reg(int32_t & StackPos, x86Reg reg);
    void fpuLoadDwordFromN64Mem(int32_t & StackPos, x86Reg reg);
    void fpuLoadInt32bFromN64Mem(int32_t & StackPos, x86Reg reg);
    void fpuLoadIntegerDword(int32_t & StackPos, void * Variable, const char * VariableName);
    void fpuLoadIntegerDwordFromX86Reg(int32_t & StackPos, x86Reg Reg);
    void fpuLoadIntegerQword(int32_t & StackPos, void * Variable, const char * VariableName);
    void fpuLoadIntegerQwordFromX86Reg(int32_t & StackPos, x86Reg Reg);
    void fpuLoadQword(int32_t & StackPos, void * Variable, const char * VariableName);
    void fpuLoadQwordFromX86Reg(int32_t & StackPos, x86Reg Reg);
    void fpuLoadQwordFromN64Mem(int32_t & StackPos, x86Reg reg);
    void fpuLoadReg(int32_t & StackPos, x86FpuValues Reg);
    void fpuMulDword(void * Variable, const char * VariableName);
    void fpuMulDwordRegPointer(x86Reg X86Pointer);
    void fpuMulQword(void * Variable, const char * VariableName);
    void fpuMulQwordRegPointer(x86Reg X86Pointer);
    void fpuMulReg(x86FpuValues reg);
    void fpuMulRegPop(x86FpuValues reg);
    void fpuNeg();
    void fpuRound();
    void fpuSqrt();
    void fpuStoreControl(void * Variable, const char * VariableName);
    void fpuStoreDword(int32_t & StackPos, void * Variable, const char * VariableName, bool pop);
    void fpuStoreDwordFromX86Reg(int32_t & StackPos, x86Reg Reg, bool pop);
    void fpuStoreDwordToN64Mem(int32_t & StackPos, x86Reg reg, bool Pop);
    void fpuStoreIntegerDword(int32_t & StackPos, void * Variable, const char * VariableName, bool pop);
    void fpuStoreIntegerDwordFromX86Reg(int32_t & StackPos, x86Reg Reg, bool pop);
    void fpuStoreIntegerQword(int32_t & StackPos, void * Variable, const char * VariableName, bool pop);
    void fpuStoreIntegerQwordFromX86Reg(int32_t & StackPos, x86Reg Reg, bool pop);
    void fpuStoreQwordFromX86Reg(int32_t & StackPos, x86Reg Reg, bool pop);
    void fpuStoreStatus();
    void fpuSubDword(void * Variable, const char * VariableName);
    void fpuSubDwordRegPointer(x86Reg X86Pointer);
    void fpuSubDwordReverse(void * Variable, const char * VariableName);
    void fpuSubQword(void * Variable, const char * VariableName);
    void fpuSubQwordRegPointer(x86Reg X86Pointer);
    void fpuSubQwordReverse(void * Variable, const char * VariableName);
    void fpuSubReg(x86FpuValues reg);
    void fpuSubRegPop(x86FpuValues reg);

    static bool Is8BitReg(x86Reg Reg);
    static uint8_t CalcMultiplyCode(Multipler Multiply);
    static uint32_t GetAddressOf(int32_t value, ...);

    void SetJump32(uint32_t * Loc, uint32_t * JumpLoc);
    void SetJump8(uint8_t * Loc, uint8_t * JumpLoc);

private:
    CX86Ops(void);
    CX86Ops(const CX86Ops &);
    CX86Ops & operator=(const CX86Ops &);

    void CodeLog(_Printf_format_string_ const char * Text, ...);

    static void BreakPointNotification(const char * FileName, int32_t LineNumber);
    static char m_fpupop[2][2];
    void AddCode8(uint8_t value);
    void AddCode16(uint16_t value);
    void AddCode32(uint32_t value);

    CCodeBlock & m_CodeBlock;
};

#define AddressOf(Addr) CX86Ops::GetAddressOf(5, (Addr))

#endif
