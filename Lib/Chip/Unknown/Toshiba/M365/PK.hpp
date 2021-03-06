#pragma once 
#include <Register/Utility.hpp>
namespace Kvasir {
//General Purpose Input_Output Port (PK)
    namespace PkData{    ///<PK Data Register
        using Addr = Register::Address<0x400c0a00,0xfffffff0,0x00000000,unsigned>;
        ///PK0
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> pk0{}; 
        ///PK1
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> pk1{}; 
        ///PK2
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> pk2{}; 
        ///PK3
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> pk3{}; 
    }
    namespace PkCr{    ///<PK Control Register
        using Addr = Register::Address<0x400c0a04,0xfffffff0,0x00000000,unsigned>;
        ///PK0C
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> pk0c{}; 
        ///PK1C
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> pk1c{}; 
        ///PK2C
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> pk2c{}; 
        ///PK3C
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> pk3c{}; 
    }
    namespace PkFr2{    ///<PK Function Register 2
        using Addr = Register::Address<0x400c0a0c,0xfffffffc,0x00000000,unsigned>;
        ///PK0F2
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> pk0f2{}; 
        ///PK1F2
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> pk1f2{}; 
    }
    namespace PkFr3{    ///<PK Function Register 3
        using Addr = Register::Address<0x400c0a10,0xfffffff0,0x00000000,unsigned>;
        ///PK0F3
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> pk0f3{}; 
        ///PK1F3
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> pk1f3{}; 
        ///PK2F3
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> pk2f3{}; 
        ///PK3F3
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> pk3f3{}; 
    }
    namespace PkPup{    ///<PK Pull-Up Control Register
        using Addr = Register::Address<0x400c0a2c,0xfffffff0,0x00000000,unsigned>;
        ///PK0UP
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> pk0up{}; 
        ///PK1UP
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> pk1up{}; 
        ///PK2UP
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> pk2up{}; 
        ///PK3UP
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> pk3up{}; 
    }
    namespace PkIe{    ///<PK Input Enable Control Register
        using Addr = Register::Address<0x400c0a38,0xfffffff0,0x00000000,unsigned>;
        ///PK0IE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> pk0ie{}; 
        ///PK1IE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> pk1ie{}; 
        ///PK2IE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> pk2ie{}; 
        ///PK3IE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> pk3ie{}; 
    }
}
