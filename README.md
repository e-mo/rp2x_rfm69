# rp2x_rfm69 - 1.0.0
A zero-assumptions library for interfacing the RP2XXX MCU family with the RFM69 family of transceivers.
### Note on using this library
This library exposes a low level interface for interacting with the Rfm69 family of transceivers with the RP2XXX microcontrollers. Usage of this library assumes intimate knowledge of your radio's datasheet, and beyond some [configuration notes](docs/configuration.md) talking about a few specific pain points which I believe are poorly represented in the documentation, I do very little to explain how the Rfm69 transceivers function.  

---
## Interface
This library is a low level interface which provides a thin level of abstraction over the SPI calls needed to configure the RFM69 family of transceivers.

[Interface Documentation](docs/interface.md)

note: this interface is incomplete and does not provide a helper function for setting/reading all registers, only those that were relevant to me at the time of writing the drivers. I welcome pull requests, and will likely fill in the remaining functionality myself at some point.

---
## RUDP Interface

I am breaking all higher level functionality into a new repo to keep these drivers pure. I am also deep in a rewrite to support using DIO pins to simplify Tx/Rx procedure. It is nearing stability. Check it out!
[rp2x_rfm69_rudp](https://github.com/e-mo/rp2x_rfm69_rudp)

---
## Examples
[tx/rx with polling](https://github.com/e-mo/rfm69_rp2040/tree/main/examples)  

---
## Other Helpful Stuff
[Notes on Configuring RFM69](docs/configuration.md)  
[RFM69HCW Datasheet](https://cdn.sparkfun.com/datasheets/Wireless/General/RFM69HCW-V1.1.pdf)

---
## Change Log
2025.04.13 - v1.0 release  
I have decided to mark this as the 1.0 release point. Not every helper function that could be built has been built, and I'm sure not every bug has been found, but I feel the interface is stable and I feel that I can commit to not making any breaking changes to the existing interface. I will continue building out the features of the driver until it is complete, but if there are helper functions you wish to see, I urge you to submit a pull request. I have a lot of projects and mostly update these drivers based on personal need, though I am responsive to the needs of other time depending. I will also do my best to properly document changes and releases here.
  
This release comes with the removal of the RUDP interface as I feel it did not make sense to have it attached directly to the drivers. A link to the new RUDP interface library can be found above. It was also a god damned mess that I made hastily with no specification so I have taken my time with the rebuild and like to think I have learned from my first pass mistakes. I had never written my own coms protocol before, you know?

---
## .plan
I am still very much actively working on some of the higher features of this library. I decided to establish a proper specification of my RUDP prodocol, which I have renamed WTP (the Wisdom Transfer Protocol), though it will still just be called RUDP in the library for simplicity. I recently added this specification to the repo. I am also rebuilding the RUDP part of the library entirely to a more sane and maintainable design. The original was built quickly to meet a specific testing goal, and if you have looked at the RUDP TX/RX functions, they are a nightmare and even I struggle to read them and make changes. I am finally utilizing the DIO ports and a creating an interrupt driven design.  

I think these changes are the correct direction and I look foward to being happier with the state of the RUDP code, as well as iproving higher level support for some of the RFM69s more advanced features.

**2025.04.13:**  
This marks the 1.0 release. I felt this cleanup and release was necessary to finally establish a baseline and get all documentation and the repo up to date. Because the RUDP interface was removed with this, I will be pushing hard to get the rudp library documentated and stable.


---  
If you need help or have a suggestion/question of any kind, contact me:  
<emorse8686@gmail.com>
