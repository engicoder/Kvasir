#pragma once 
#include <Register/Utility.hpp>
namespace Kvasir {
//USART
    namespace Usart1Cfg{    ///<USART Configuration register. Basic USART configuration settings that typically are not changed during operation.
        using Addr = Register::Address<0x40068000,0x00000000,0x00000000,unsigned>;
        ///USART Enable.
        enum class EnableVal {
            disabledTheUsart=0x00000000,     ///<Disabled. The USART is disabled and the internal state machine and counters are reset. While Enable = 0, all USART interrupts  are disabled. When Enable is set again, CFG and most other control bits remain unchanged. For instance, when re-enabled, the USART will immediately generate a TxRdy interrupt if  enabled because the transmitter has been reset and is therefore available.
            enabledTheUsartI=0x00000001,     ///<Enabled. The USART is enabled for operation.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,EnableVal> enable{}; 
        namespace EnableValC{
            constexpr Register::FieldValue<decltype(enable)::Type,EnableVal::disabledTheUsart> disabledTheUsart{};
            constexpr Register::FieldValue<decltype(enable)::Type,EnableVal::enabledTheUsartI> enabledTheUsartI{};
        }
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Selects the data size for the USART.
        enum class DatalenVal {
            v7BitDataLength=0x00000000,     ///<7 bit Data length.
            v8BitDataLength=0x00000001,     ///<8 bit Data length.
            v9BitDataLengthT=0x00000002,     ///<9 bit data length. The 9th bit is commonly used for addressing in multidrop mode. See the ADDRDET bit in the CTRL register.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,2),Register::ReadWriteAccess,DatalenVal> datalen{}; 
        namespace DatalenValC{
            constexpr Register::FieldValue<decltype(datalen)::Type,DatalenVal::v7BitDataLength> v7BitDataLength{};
            constexpr Register::FieldValue<decltype(datalen)::Type,DatalenVal::v8BitDataLength> v8BitDataLength{};
            constexpr Register::FieldValue<decltype(datalen)::Type,DatalenVal::v9BitDataLengthT> v9BitDataLengthT{};
        }
        ///Selects what type of parity is used by the USART.
        enum class ParityselVal {
            noParity=0x00000000,     ///<No parity.
            evenParityAddsA=0x00000002,     ///<Even parity. Adds a bit to each character such that the number of 1s in a transmitted character is even, and the number of 1s in a received character is expected to be even.
            oddParityAddsAB=0x00000003,     ///<Odd parity. Adds a bit to each character such that the number of 1s in a transmitted character is odd, and the number of 1s in a received character is expected to be odd.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,4),Register::ReadWriteAccess,ParityselVal> paritysel{}; 
        namespace ParityselValC{
            constexpr Register::FieldValue<decltype(paritysel)::Type,ParityselVal::noParity> noParity{};
            constexpr Register::FieldValue<decltype(paritysel)::Type,ParityselVal::evenParityAddsA> evenParityAddsA{};
            constexpr Register::FieldValue<decltype(paritysel)::Type,ParityselVal::oddParityAddsAB> oddParityAddsAB{};
        }
        ///Number of stop bits appended to transmitted data. Only a single stop bit is required for received data.
        enum class StoplenVal {
            v1StopBit=0x00000000,     ///<1 stop bit.
            v2StopBitsThisSe=0x00000001,     ///<2 stop bits. This setting should only be used for asynchronous communication.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,StoplenVal> stoplen{}; 
        namespace StoplenValC{
            constexpr Register::FieldValue<decltype(stoplen)::Type,StoplenVal::v1StopBit> v1StopBit{};
            constexpr Register::FieldValue<decltype(stoplen)::Type,StoplenVal::v2StopBitsThisSe> v2StopBitsThisSe{};
        }
        ///Reserved. Only write 0 to this bit.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///CTS Enable. Determines whether CTS is used for flow control. CTS can be from the input pin, or from the USART's own RTS if loopback mode is enabled. See Section 16.7.3 for more information.
        enum class CtsenVal {
            noFlowControlThe=0x00000000,     ///<No flow control. The transmitter does not receive any automatic flow control signal.
            flowControlEnabled=0x00000001,     ///<Flow control enabled. The transmitter uses external or internal CTS for flow control purposes.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,CtsenVal> ctsen{}; 
        namespace CtsenValC{
            constexpr Register::FieldValue<decltype(ctsen)::Type,CtsenVal::noFlowControlThe> noFlowControlThe{};
            constexpr Register::FieldValue<decltype(ctsen)::Type,CtsenVal::flowControlEnabled> flowControlEnabled{};
        }
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,10),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Selects synchronous or asynchronous operation.
        enum class SyncenVal {
            asynchronousModeIs=0x00000000,     ///<Asynchronous mode is selected.
            synchronousModeIs=0x00000001,     ///<Synchronous mode is selected.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,SyncenVal> syncen{}; 
        namespace SyncenValC{
            constexpr Register::FieldValue<decltype(syncen)::Type,SyncenVal::asynchronousModeIs> asynchronousModeIs{};
            constexpr Register::FieldValue<decltype(syncen)::Type,SyncenVal::synchronousModeIs> synchronousModeIs{};
        }
        ///Selects the clock polarity and sampling edge of received data in synchronous mode.
        enum class ClkpolVal {
            fallingEdgeUnRxd=0x00000000,     ///<Falling edge. Un_RXD is sampled on the falling edge of SCLK.
            risingEdgeUnRxd=0x00000001,     ///<Rising edge. Un_RXD is sampled on the rising edge of SCLK.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(12,12),Register::ReadWriteAccess,ClkpolVal> clkpol{}; 
        namespace ClkpolValC{
            constexpr Register::FieldValue<decltype(clkpol)::Type,ClkpolVal::fallingEdgeUnRxd> fallingEdgeUnRxd{};
            constexpr Register::FieldValue<decltype(clkpol)::Type,ClkpolVal::risingEdgeUnRxd> risingEdgeUnRxd{};
        }
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(13,13),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Synchronous mode Master select.
        enum class SyncmstVal {
            slaveWhenSynchron=0x00000000,     ///<Slave. When synchronous mode is enabled, the USART is a slave.
            masterWhenSynchro=0x00000001,     ///<Master. When synchronous mode is enabled, the USART is a master. In asynchronous mode, the baud rate clock will be output on SCLK if it is connected to a pin.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(14,14),Register::ReadWriteAccess,SyncmstVal> syncmst{}; 
        namespace SyncmstValC{
            constexpr Register::FieldValue<decltype(syncmst)::Type,SyncmstVal::slaveWhenSynchron> slaveWhenSynchron{};
            constexpr Register::FieldValue<decltype(syncmst)::Type,SyncmstVal::masterWhenSynchro> masterWhenSynchro{};
        }
        ///Selects data loopback mode.
        enum class LoopVal {
            normalOperation=0x00000000,     ///<Normal operation.
            loopbackModeThis=0x00000001,     ///<Loopback mode. This provides a mechanism to perform diagnostic loopback testing for USART data. Serial data from the transmitter (Un_TXD) is connected internally to serial input of the receive (Un_RXD). Un_TXD and Un_RTS activity will also appear on external pins if these functions are configured to appear on device pins. The receiver RTS signal is also looped back to CTS and performs flow control if enabled by CTSEN.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,15),Register::ReadWriteAccess,LoopVal> loop{}; 
        namespace LoopValC{
            constexpr Register::FieldValue<decltype(loop)::Type,LoopVal::normalOperation> normalOperation{};
            constexpr Register::FieldValue<decltype(loop)::Type,LoopVal::loopbackModeThis> loopbackModeThis{};
        }
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Usart1Ctrl{    ///<USART Control register. USART control settings that are more likely to change during operation.
        using Addr = Register::Address<0x40068004,0x00000000,0x00000000,unsigned>;
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Break Enable.
        enum class TxbrkenVal {
            normalOperation=0x00000000,     ///<Normal operation.
            continuousBreakIs=0x00000001,     ///<Continuous break is sent immediately when this bit is set, and remains until this bit is cleared. A break may be sent without danger of corrupting any currently transmitting character if the transmitter is first disabled (TXDIS in CTRL is set) and then waiting for the transmitter to be disabled (TXDISINT in STAT = 1) before writing 1 to TXBRKEN.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,TxbrkenVal> txbrken{}; 
        namespace TxbrkenValC{
            constexpr Register::FieldValue<decltype(txbrken)::Type,TxbrkenVal::normalOperation> normalOperation{};
            constexpr Register::FieldValue<decltype(txbrken)::Type,TxbrkenVal::continuousBreakIs> continuousBreakIs{};
        }
        ///Enable address detect mode.
        enum class AddrdetVal {
            enabledTheUsartR=0x00000000,     ///<Enabled. The USART receiver is enabled for all incoming data.
            disabledTheUsart=0x00000001,     ///<Disabled. The USART receiver ignores incoming data that does not have the most significant bit of the data (typically the 9th bit) = 1. When the data MSB bit = 1, the receiver treats the incoming data normally, generating a received data interrupt. Software can then check the data to see if this is an address that should be handled. If it is, the ADDRDET bit is cleared by software and further incoming data is handled normally.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,AddrdetVal> addrdet{}; 
        namespace AddrdetValC{
            constexpr Register::FieldValue<decltype(addrdet)::Type,AddrdetVal::enabledTheUsartR> enabledTheUsartR{};
            constexpr Register::FieldValue<decltype(addrdet)::Type,AddrdetVal::disabledTheUsart> disabledTheUsart{};
        }
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,3),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Transmit Disable.
        enum class TxdisVal {
            notDisabledUsart=0x00000000,     ///<Not disabled. USART transmitter is not disabled.
            disabledUsartTran=0x00000001,     ///<Disabled. USART transmitter is disabled after any character currently being transmitted is complete. This feature can be used to facilitate software flow control.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,TxdisVal> txdis{}; 
        namespace TxdisValC{
            constexpr Register::FieldValue<decltype(txdis)::Type,TxdisVal::notDisabledUsart> notDisabledUsart{};
            constexpr Register::FieldValue<decltype(txdis)::Type,TxdisVal::disabledUsartTran> disabledUsartTran{};
        }
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Continuous Clock generation. By default, SCLK is only output while data is being transmitted in synchronous mode.
        enum class CcVal {
            clockOnCharacter=0x00000000,     ///<Clock on character. In synchronous mode, SCLK cycles only when characters are being sent on Un_TXD or to complete a character that is being received.
            continuousClockSc=0x00000001,     ///<Continuous clock. SCLK runs continuously in synchronous mode, allowing characters to be received on Un_RxD independently from transmission on Un_TXD).
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,CcVal> cc{}; 
        namespace CcValC{
            constexpr Register::FieldValue<decltype(cc)::Type,CcVal::clockOnCharacter> clockOnCharacter{};
            constexpr Register::FieldValue<decltype(cc)::Type,CcVal::continuousClockSc> continuousClockSc{};
        }
        ///Clear Continuous Clock.
        enum class ClrccVal {
            noAffectOnTheCc=0x00000000,     ///<No affect on the CC bit.
            autoClearTheCcB=0x00000001,     ///<Auto-clear. The CC bit is automatically cleared when a complete character has been received. This bit is cleared at the same time.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,ClrccVal> clrcc{}; 
        namespace ClrccValC{
            constexpr Register::FieldValue<decltype(clrcc)::Type,ClrccVal::noAffectOnTheCc> noAffectOnTheCc{};
            constexpr Register::FieldValue<decltype(clrcc)::Type,ClrccVal::autoClearTheCcB> autoClearTheCcB{};
        }
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,10),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Usart1Stat{    ///<USART Status register. The complete status value can be read here. Writing 1s clears some bits in the register. Some bits can be cleared by writing a 1 to them.
        using Addr = Register::Address<0x40068008,0x00000000,0x00000000,unsigned>;
        ///Receiver Ready flag. When 1, indicates that data is available to be read from the receiver buffer. Cleared after a read of the RXDATA or RXDATASTAT registers.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> rxrdy{}; 
        ///Receiver Idle. When 0, indicates that the receiver is currently in the process of receiving data. When 1, indicates that the receiver is not currently in the process of receiving data.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> rxidle{}; 
        ///Transmitter Ready flag. When 1, this bit indicates that data may be written to the transmit buffer. Previous data may still be in the process of being transmitted. Cleared when data is written to TXDATA until the data is moved to the transmit shift register.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> txrdy{}; 
        ///Transmitter Idle. When 0, indicates that the transmitter is currently in the process of sending data.When 1, indicate that the transmitter is not currently in the process of sending data.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> txidle{}; 
        ///This bit reflects the current state of the CTS signal, regardless of the setting of the CTSEN bit in the CFG register. This will be the value of the CTS input pin unless loopback mode is enabled.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> cts{}; 
        ///This bit is set when a change in the state is detected for the CTS flag above. This bit is cleared by software.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> deltacts{}; 
        ///Transmitter Disabled Interrupt flag. When 1, this bit indicates that the USART transmitter is fully idle after being disabled via the TXDIS in the CFG register (TXDIS = 1).
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,unsigned> txdisint{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Overrun Error interrupt flag. This flag is set when a new character is received while the receiver buffer is still in use. If this occurs, the newly received character in the shift register is lost.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> overrunint{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Received Break. This bit reflects the current state of the receiver break detection logic. It is set when the Un_RXD pin remains low for 16 bit times. Note that FRAMERRINT will also be set when this condition occurs because the stop bit(s) for the character would be missing. RXBRK is cleared when the Un_RXD pin goes high.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,10),Register::ReadWriteAccess,unsigned> rxbrk{}; 
        ///This bit is set when a change in the state of receiver break detection occurs. Cleared by software.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,unsigned> deltarxbrk{}; 
        ///This bit is set when a start is detected on the receiver input and subsequently confirmed by a mid-bit sample. Its purpose is primarily to allow wakeup from Power-down mode immediately when a start is detected. Cleared by software.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(12,12),Register::ReadWriteAccess,unsigned> start{}; 
        ///Framing Error interrupt flag. This flag is set when a character is received with a missing stop bit at the expected location. This could be an indication of a baud rate or configuration mismatch with the transmitting source.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(13,13),Register::ReadWriteAccess,unsigned> framerrint{}; 
        ///Parity Error interrupt flag. This flag is set when a parity error is detected in a received character, if parity is enabled via the Parity field in the CFG register.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(14,14),Register::ReadWriteAccess,unsigned> parityerrint{}; 
        ///Received Noise interrupt flag. This bit is valid when there is a character to be read in the RXDATA register and reflects the status of that character. Three samples of received data are taken in order to determine the value of each received data bit, except in synchronous mode. This acts as a noise filter if one sample disagrees. The Noise bit is set when a received data bit contains one disagreeing sample. This could indicate line noise, a baud rate or character format mismatch, or loss of synchronization during data reception. RXNOISEINT is not updated during a received break.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,15),Register::ReadWriteAccess,unsigned> rxnoiseint{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Usart1Intenset{    ///<Interrupt Enable read and Set register. Contains an individual interrupt enable bit for each potential USART interrupt. A complete value may be read from this register. Writing a 1 to any implemented bit position causes that bit to be set.
        using Addr = Register::Address<0x4006800c,0x00000000,0x00000000,unsigned>;
        ///When 1, enables an interrupt when there is a received character available to be read from the RXDATA register.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> rxrdyen{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///When 1, enables an interrupt when the TXDATA register is available to take another character to transmit.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> txrdyen{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,3),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///When 1, enables an interrupt when there is a change in the state of the CTS input.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> deltactsen{}; 
        ///When 1, enables an interrupt when the transmitter is fully disabled as indicated by the TXDISINT flag in STAT. See description of the TXDISINT bit for details.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,unsigned> txdisinten{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///When 1, enables an interrupt when an overrun error occurred.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> overrunen{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,9),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///When 1, enables an interrupt when a change of state has occurred in the detection of a received break condition (break condition asserted or deasserted).
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,unsigned> deltarxbrken{}; 
        ///When 1, enables an interrupt when a received start bit has been detected.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(12,12),Register::ReadWriteAccess,unsigned> starten{}; 
        ///When 1, enables an interrupt when a framing error has been detected.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(13,13),Register::ReadWriteAccess,unsigned> framerren{}; 
        ///When 1, enables an interrupt when a parity error has been detected.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(14,14),Register::ReadWriteAccess,unsigned> parityerren{}; 
        ///When 1, enables an interrupt when noise is detected. See description of the RXNOISEINT bit in Table 164.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,15),Register::ReadWriteAccess,unsigned> rxnoiseen{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Usart1Intenclr{    ///<Interrupt Enable Clear register. Allows clearing any combination of bits in the INTENSET register. Writing a 1 to any implemented bit position causes the corresponding bit to be cleared.
        using Addr = Register::Address<0x40068010,0x00000000,0x00000000,unsigned>;
        ///Writing 1 clears the corresponding bit in the INTENSET register.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> rxrdyclr{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Writing 1 clears the corresponding bit in the INTENSET register.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> txrdyclr{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,3),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Writing 1 clears the corresponding bit in the INTENSET register.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> deltactsclr{}; 
        ///Writing 1 clears the corresponding bit in the INTENSET register.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,unsigned> txdisintclr{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Writing 1 clears the corresponding bit in the INTENSET register.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> overrunclr{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,9),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Writing 1 clears the corresponding bit in the INTENSET register.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,unsigned> deltarxbrkclr{}; 
        ///Writing 1 clears the corresponding bit in the INTENSET register.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(12,12),Register::ReadWriteAccess,unsigned> startclr{}; 
        ///Writing 1 clears the corresponding bit in the INTENSET register.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(13,13),Register::ReadWriteAccess,unsigned> framerrclr{}; 
        ///Writing 1 clears the corresponding bit in the INTENSET register.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(14,14),Register::ReadWriteAccess,unsigned> parityerrclr{}; 
        ///Writing 1 clears the corresponding bit in the INTENSET register.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,15),Register::ReadWriteAccess,unsigned> rxnoiseclr{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Usart1Rxdata{    ///<Receiver Data register. Contains the last character received.
        using Addr = Register::Address<0x40068014,0x00000000,0x00000000,unsigned>;
        ///The USART Receiver Data register contains the next received character. The number of bits that are relevant depends on the USART configuration settings.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,0),Register::ReadWriteAccess,unsigned> rxdat{}; 
        ///Reserved, the value read from a reserved bit is not defined.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,9),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Usart1Rxdatastat{    ///<Receiver Data with Status register. Combines the last character received with the current USART receive status. Allows software to recover incoming data and status together.
        using Addr = Register::Address<0x40068018,0x00000000,0x00000000,unsigned>;
        ///The USART Receiver Data register contains the next received character. The number of bits that are relevant depends on the USART configuration settings.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,0),Register::ReadWriteAccess,unsigned> rxdat{}; 
        ///Reserved, the value read from a reserved bit is not defined.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(12,9),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Framing Error status flag. This bit is valid when there is a character to be read in the RXDATA register and reflects the status of that character. This bit will set when the character in RXDAT was received with a missing stop bit at the expected location. This could be an indication of a baud rate or configuration mismatch with the transmitting source.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(13,13),Register::ReadWriteAccess,unsigned> framerr{}; 
        ///Parity Error status flag. This bit is valid when there is a character to be read in the RXDATA register and reflects the status of that character. This bit will be set when a parity error is detected in a received character.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(14,14),Register::ReadWriteAccess,unsigned> parityerr{}; 
        ///Received Noise flag. See description of the RxNoiseInt bit in Table 164.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,15),Register::ReadWriteAccess,unsigned> rxnoise{}; 
        ///Reserved, the value read from a reserved bit is not defined.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Usart1Txdata{    ///<Transmit Data register. Data to be transmitted is written here.
        using Addr = Register::Address<0x4006801c,0x00000000,0x00000000,unsigned>;
        ///Writing to the USART Transmit Data Register causes the data to be transmitted as soon as the transmit shift register is available.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,0),Register::ReadWriteAccess,unsigned> txdat{}; 
        ///Reserved. Only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,9),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Usart1Brg{    ///<Baud Rate Generator register. 16-bit integer baud rate divisor value.
        using Addr = Register::Address<0x40068020,0x00000000,0x00000000,unsigned>;
        ///This value is used to divide the USART input clock to determine the baud rate, based on the input clock from the FRG. 0 = The FRG clock is used directly by the USART function. 1 = The FRG clock is divided by 2 before use by the USART function. 2 = The FRG clock is divided by 3 before use by the USART function. ... 0xFFFF = The FRG clock is divided by 65,536 before use by the USART function.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> brgval{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Usart1Intstat{    ///<Interrupt status register. Reflects interrupts that are currently enabled.
        using Addr = Register::Address<0x40068024,0x00000000,0x00000000,unsigned>;
        ///Receiver Ready flag.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> rxrdy{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Transmitter Ready flag.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> txrdy{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,3),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///This bit is set when a change in the state of the CTS input is detected.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> deltacts{}; 
        ///Transmitter Disabled Interrupt flag.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,unsigned> txdisint{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Overrun Error interrupt flag.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> overrunint{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,9),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///This bit is set when a change in the state of receiver break detection occurs.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,unsigned> deltarxbrk{}; 
        ///This bit is set when a start is detected on the receiver input.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(12,12),Register::ReadWriteAccess,unsigned> start{}; 
        ///Framing Error interrupt flag.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(13,13),Register::ReadWriteAccess,unsigned> framerrint{}; 
        ///Parity Error interrupt flag.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(14,14),Register::ReadWriteAccess,unsigned> parityerrint{}; 
        ///Received Noise interrupt flag.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,15),Register::ReadWriteAccess,unsigned> rxnoiseint{}; 
        ///Reserved. Read value is undefined, only zero should be written.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
}
