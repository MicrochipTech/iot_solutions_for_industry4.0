# AIoT Solutions For Industry 4.0
<img src="Doc/IoT-Made-Easy-Logo.png" width=100>

> “Wireless Made Fun!" - IoT Solutions for Industry 4.0

1. [Facts and challenges of Industry 4.0](#step1)
1. [Our solution : "IoT Solutions for Industry 4.0"](#step2)
	1. [System architecture](#step2a)
	1. [First and foremost, made secure and robust](#step2b)
	1. [Cloud solutions](#step2c)
	1. [Technology bricks](#step2d)
		1. [Linux](#step2d1)
		1. [Security](#step2d2)
		1. [Wi-Fi](#step2d3)
		1. [Zigbee Network](#step2d4)
1. [Do It Yourself](#step3)
	1. [Bill of materials](#step3a)
	1. [Step by step guide](#step3b)
	1. [Hardware](#step3c)
	1. [Software](#step3d)
		1. [Linux Python Application](#step3d1)
		1. [Zigbee Mesh Application](#step3d2)
		1. [AWS Web Application](#step3d3)

## Facts and challenges of Industry 4.0 <a name="step1"></a>

The fourth industrial revolution (so called Industry 4.0) is a reality, happening now with production lines being upgraded with cloud connectivity. Equipment (sensors and actuators, timers, PLC, drives...) gets smarter and augmented with Machine Learning, Cloud and Edge Artificial Intelligence along other analytics functions.</br>
Every unit can now add its value to the entire system along to every single link of the chain, as every node can share valuable data to all and at the same time make decisions on its own. It’s a great opportunity to better track supplies, automate production, implement predictive maintenance and much more.</br>
</br>
But here come 2 challenges for developers building Industry 4.0 products:</br>
1)	Highest robustness and reliability standards are required </br>
2)	Vulnerability is not an option, highest cyber-security standards are required </br>
</br>
<img src="Doc/industry40.png" alt="drawing" width="480"/>
</br>

## Our solution : "AIoT Solutions for Industry 4.0" <a name="step2"></a>

![](Doc/aiot_1.jpg)</br>

To help you go through these challenges, Microchip Technology has built this demonstrator, integrating our state-of-the-art solutions with a focus on robustness and security. This application manages a sensor network while controlling a robot, and report data thru an HMI. Several use cases are provided (Station, SoftAP or concurrent modes - Ethernet, Wifi and SubGHz connectivity – Standalone, AWS IoT or AWS Greengrass…) to best adapt our solutions to your need.</br>
Check it out here:</br>
<a href="https://youtu.be/EOvJPf0HmIA" target="_blank"><img src="Doc/youtube_video.png" width="240" height="180" border="10" /></a>
</br>
And enjoy this Github session
</br>

### System architecture <a name="step2a"></a>

Main unit (see “SAM9X75 / SAM9X60 Curiosity” Development Kit) has the following functionalities</br>
- First and foremost, it drives the robot operations. This will be here your typical factory automation operations: moving, cutting, bending, pressing or connecting pieces altogether</br>
- Collecting and processing sensors data</br>
The automation operations described earlier can only be possible if robot is fully aware of its environment. So, the need of collecting data related to the assembly line environment (input), the operation performed (the output or result of a given operation) but also the robot status </br>
    - Are the pieces available for process, ready to be manipulated, in the expected position? </br>
    - Was the operation performed as expected, with no defect? </br>
    - Is the robot back to the expected position? Capable of executing next operation? Do we detect any suspicious behaviour or status that could later damage robot or create a line down (see high temperature, unexpected vibration, noise…)?</br>
- Reports status of its operation to and gets directive from a local console (use case 1), or from a global and decentralized system managed from the cloud (use case 2, 3 or 4)</br>
- Operate safely to say, support an emergency shut down mode (robot could get stopped in no time)</br>
- Last but not least, monitor its own environment to prevent future issue: predictive maintenance</br>

To ensure real time operations, with high robustness and security, gateway is based on SAM9X75 MPU running a Linux Operating system, with robust Wifi Link Controller (WILCS02) fully tested for interoperability and CE/FCC/IC certified
</br></br>
<img src="Doc/sam9x75_wilsc02.jpg" alt="drawing" width="200"/>
</br></br>
Sensors are connected to the gateway thru a Zigbee network, based on WBZ451 Module and its associated development kit <a href="https://www.microchip.com/en-us/development-tool/EV96B94A" target="_blank">(see PIC32CX-BZ2 and WBZ451 Curiosity Development Board from Microchip)</a></br>
WBZ451 supports differnt protocol such as IEEE 802.15.4 PHY based protocols, Microchip's own MiWi Networking protocols for self-healing Point-to-point, Star and Mesh networking, Thread and Zigbee (see <a href="https://www.microchip.com/en-us/products/wireless-connectivity/zigbee" target="_blank">Microchip Zigbee Home page</a>). This is the network we will use here in this demo.</br>
- Zigbee Network with Custom Cluster
- “PAN Coordinator” connected to “SAM9X75 Curiosity” Development Kit
- 2 sensors used for data harvesting 
    - Sensors set-up as “End Device”
    - Sensor 1 acquires the ambient temperature 
    - Sensor 2 acquires the vibration of arm robot, to implement predictive maintenance
	
<img src="Doc/demo_network_sam9x.png" alt="drawing" width="560"/></br>
</br>
Built for Industry 4.0, this demo is covering 4 use cases:</br>
- Use case 1 - Standalone mode (OFF Line) : application data pushed to SmartPhone (Wifi Gateway is set in SoftAP mode) while sensor data gets collected via robust Zigbee® Mesh network (see Zigbee® MCU Products)
</br><img src="Doc/architecture_use_case_1.png" alt="drawing" width="560"/></br>
</br><img src="Doc/architecture_use_case_1_dashboard.png" alt="drawing" width="560"/></br>
- Use case 2 - ON Line mode with AWS IoT : application data is pushed to the Cloud using AWS IoT (Wifi Gateway is set in Station mode). No change for sensor network compared to use case 1 : data gets collected via robust Zigbee® Mesh network (see Zigbee® MCU Products)
</br><img src="Doc/architecture_use_case_2.png" alt="drawing" width="560"/></br>
- Use case 3 - Concurrent mode (Wifi as SoftAP and Station mode): Wifi Gateway supports and operates simultaneously Station and SoftAP modes, aggregating Use cases 1 and 2. No change for sensor network compared to use cases 1 and 2 : data gets collected via robust Zigbee® Mesh network (see Zigbee® MCU Products)
</br><img src="Doc/architecture_use_case_3.png" alt="drawing" width="560"/></br>
- Use case 4 - ON Line mode with AWS Greengrass: robust connectivity taking full leverage of AWS Greengrass. Here, demonstrator is connected to the Cloud through Ethernet wired connectivity. Sensors now communicate to the Gateway thru Wi-Fi®
</br><img src="Doc/architecture_use_case_4.png" alt="drawing" width="560"/></br>

### First and foremost, made secure and robust<a name="step2b"></a>

- **Robust by design**</br>
Multiple options (Wireless SOM, SOM, discrete approach with certified module or full discrete implementation) mitigate your risk, proposing you need based on your application constraints (time to market, RF expertise, cost target…). 
This approach is reinforced by reference implementation and reference design provided by Microchip. Copy paste, you can’t make it easier. Microchip also have Chip Down Package, for customers using WILCS02 QFN rather than the certified modules.

</br>
<img src="Doc/robust_and_secure.png" alt="drawing" width="570"/>
</br>

SOM remains good strategy to get started in no time, allowing fast prototyping and shorten your learning curve. And in such mitigate one more time risk.

<img src="Doc/som_design.png" alt="drawing" width="570"/>

- **Testing and Certification : one step further for higher robustness**</br>
Microchip extensively tests silicon, modules & firmware for interoperability and connectivity</br>
    - In-house Certification prior to agency submission</br>
    - SQA & regression testing prior to release</br>
    - Gauntlet automated testing with 57 access points</br>
        - New APs added quarterly</br>
        - Full list <a href="https://www.microchip.com/wi-fi-interoperability" target="_blank">here</a></br>
<img src="Doc/wifi_interop.png" alt="drawing" width="400"/>

- And Microchip certifies its WiFi solutions, see <a href="https://www.microchip.com/en-us/development-tool/ev74a47a" target="_blank">WILCS02 Home Page</a></b

- **End to end Linux approach for all Microchip products**</br>
<img src="Doc/smart_connected_secure.png" alt="drawing" width="400"/></br>
Solution is developed with full system approach, to ensure that every products interact with highest performance, security and robustness for Linux application. Connecting all dots, making your system Smart, Secure and Connected.
    - Comprehensive <a href="https://www.microchip.com/mpu" target="_blank">MPU portfolio</a>
        - Dedicated internal Linux application team
		- Microchip is committed to Linux Kernel mainlining (In-house maintainer)
        - Target Long-Term Support (LTS) Linux releases
		- Support official LTS kernels for customer peace of mind
		- All Microchip MPUs in production are supported on new kernels
        - Regular posted releases and updates
        - Linux kernel, Yocto / Buildroot and OpenWRT distributions maintained and updated
        - Bug fixes, patches, graphical layers, Python, demo images for all evaluation boards available
        - Community fixes bugs, adds enhancements between releases
        - Free Linux® kernel 4.14.x, see <a href="https://www.linux4SAM.com" target="_blank">linux4SAM.com</a>
    - Wifi portfolio with dedicated <a href="https://www.microchip.com/mpu" target="_blank">Linux ecosystem</a>
        - WILCS02 Wi-Fi Link Controller Linux User Guide
        - Linux Driver for WILCS02
        - WILC Devices Linux Porting Guide
        - WILCS02  Wi-Fi Link Controller Linux Driver Release Notes v3.0
        - WILCS02  Evaluation Kit Design Files
        - <a href="www.microchip.com/design-centers/wireless-connectivity/embedded-wi-fi/get-started-with-wi-fi-for-linux" target="_blank">Wifi Getting Started for Linux</a>
    - Secure Element solution: <a href="https://www.microchip.com/atecc608a" target="_blank">ATECC608A</a>
        - <a href="https://github.com/MicrochipTech/cryptoauthlib" target="_blank">CryptoAuthLib for a Linux project</a>
        - <a href="https://github.com/MicrochipTech/cryptoauthlib/wiki/Greengrass-HSI" target="_blank">AWS IoT Greengrass Hardware Security Interface (HSI)</a>
</br>

- **Because a Secure Element matters!**</br>
    - With Trust Platform, leverage Microchip  Secure Manufacturing Infrastructure to Securely Provision Credentials in Your Products.
For deployments of as few as ten units to up to many thousands of devices, Microchip Trust Platform is a cost-effective and flexible solution for onboarding our secure elements in your design and accelerating your product’s time to market.
The Trust Platform is composed of a family of pre-provisioned, pre-configured or fully customizable secure elements.
Credentials are generated inside each secure element’s boundary by leveraging our Hardware Secure Modules (HSMs) that are installed in Microchip factories.
    - It makes Security simple and easy to implement. Available and affordable to all applications even with low volume.
With an end to end Linux approach, Microchip solution provides all hardware reference design and firmware drivers, to get started your application in no time.
So there is no excuse to bring security to your device.
    - The Trust Platform offers three tiers of secure elements—Trust&GO, TrustFLEX and TrustCUSTOM—to provide you with the options and flexibility to meet the requirements of your company’s security model.

<img src="Doc/trustplatform.png" alt="drawing" width="720"/></br>

SAM9X75 : <a href="https://microchipdeveloper.com/authentication:trust-platform" target="_blank">Linux drivers with Complete Stack solution available</a></br>
<img src="Doc/wireless_som_ecc.png" alt="drawing" width="400"/>
</br>

- **Because a Secure MPU matters too!**</br>
Comprehensive security feature is embedded inside the SAM9X75 including:</br>
    - Die and Package Security
    - Secure back-up SRAM
    - Secure master key registers
    - Integrity Check Monitor (SHA256)
    - On-the-fly External Memory Encryption
    - RSA/ECC cryptography
    - AES, 3DES, TRNG, SHA, HW acceleration
    - Unique ID -64 bit
    - Customer fuses
    - Permanent Jtag disable by fuses
    - Secure RTC with time stamp
    - Secure Boot & SAM-BA in Secure Mode
	</br></br>
	</br></br>
Check <a href="https://www.microchip.com/mpu" target="_blank">here</a> for more information</br>
<img src="Doc/sama5d27.png" alt="drawing" width="80"/>

- **Cloud solutions for robust and secure industrial applications: AWS Greengrass**</br>
AWS Greengrass is a software that extends AWS Cloud capabilities to local devices, making it possible for those devices to collect and analyse data closer to the source of information, while also securely communicating with each other on local networks.</br>

    - In other way, it brings real time performance to the next level, with no compromise on robustness and security. Among the key features from AWS Greengrass making end node robust and secure, let’s underline
        - lambda runtime that allows you to execute serverless instructions if needed.
        - A shadow implementation, this means that a Thing has a JSON file (the shadow) where all of its parameters/variables are set and can be modified with lambda functions from the core or from the cloud.
        - A message manager: when the core needs to restart, the Things can still send messages and the core will save them until the core has restarted again.
        - A discovery service, it is a service mainly used by the Things to get certificates to connect to a Greengrass Core.
        - An Over-the-air update agent that allows updating one or more Greengrass Cores on a network at the same time or on predefined schedules. The devices with the Greengrass core will need to have the WiFi activated for this feature to work.
        - A machine learning inference, meaning that the training is done on the cloud servers but the model (the “brain” of the AI) is on the Greengrass device. Better distribution of the tasks for more efficient and robust process.
</br>
<img src="Doc/greengrass_topview.png" alt="drawing" width="570"/> </br>
<img src="Doc/greengrass_security.png" alt="drawing" width="570"/></br>
Check <a href="https://docs.aws.amazon.com/greengrass/latest/developerguide/what-is-gg.html" target="_blank">here</a> for more information</br>
Check also this nice <a href="http://ww1.microchip.com/downloads/en/Appnotes/Getting-Started-with-AWS-Greengrass-on-SAMA5D2-Application-Note-DS00003170A.pdf" target="_blank">Application note AN3170</a>, helping you getting started with AWS Greengrass on Microchip SAMAD2 MPU</br>
<img src="Doc/an3170.png" alt="drawing" width="400"/>

### Cloud solutions<a name="step2c"></a>
This demo is using AWS-IoT and AWS-Greengrass but we are not limited to one cloud provider. 
We have partnerships with the largest cloud computing companies.</br>
- <a href="https://www.microchip.com/design-centers/internet-of-things/amazon-web-services" target="_blank">Amazon Web Services</a></br>
	- <a href="https://www.microchip.com/design-centers/internet-of-things/amazon-web-services/intelligent-gateways" target="_blank">AWS Greengrass overview</a></br>
	- <a href="https://www.microchip.com/wwwappnotes/appnotes.aspx?appnote=en611788" target="_blank">Get started with AWS Greengrass</a></br>
- <a href="https://www.microchip.com/design-centers/internet-of-things/google-cloud-iot" target="_blank">Google Cloud IoT</a></br>
- <a href="https://www.microchip.com/design-centers/internet-of-things/microsoft-azure-cloud-computing" target="_blank">Microsoft Azure</a></br>
	- <a href="https://github.com/MicrochipTech/Azure-IoT-Heart-rate-monitor" target="_blank">Azure IoT Heart Rate Monitor Demo</a></br>

### Technology bricks<a name="step2d"></a>

Total System Solution from Microchip:</br>
- Smart   : PIC32 MCU, SAM9X75 MPU</br>
- Connect : WINC/WILC Wi-Fi controllers, WBZ451 MCU</br>
- Secure  : ATECC608A Secure Element</br>
Comprehensive firmware ecosystem, from Sensor to Cloud (AWS IoT Core, Microsoft Azure, Google GCP)</br>

End to End approach, Firmware and Harwdare (MCU & MPU), Secure Element, Interoperability testing, Regulatory and Alliance Certifications</br>

#### Linux<a name="step2d1"></a>

<a href="https://www.microchip.com/design-centers/wireless-connectivity/embedded-wi-fi/get-started-with-wi-fi-for-linux" target="_blank">Get Started</a> with Wi-Fi® for Applications Using the Linux® Operating System</br>

<a href="https://www.microchip.com/som" target="_blank">Linux MPU System On Modules</a></br>
<img src="Doc/soms.png" alt="drawing" width="570"/> </br>

Microchip uses its <a href="http://www.at91.com/linux4sam/bin/view/Linux4SAM" target="_blank">linux4sam.org</a> website to provide access to new developments which are reviewed by our Linux maintainers and fully tested on our hardware platforms.</br>
<a href="https://www.microchip.com/design-centers/32-bit-mpus/linux-os-for-mpus" target="_blank">Linux OS for MPUs</a></br>

For the purpose of this demo, linux4sam Github repo has been used for building the image:</br>
- <a href="https://github.com/linux4sam/linux-at91" target="_blank">Linux Kernel 4.19</a></br>
- <a href="https://github.com/linux4sam/buildroot-at91" target="_blank">Buildroot 2019.05</a></br>

#### Security<a name="step2d2"></a>

<a href="https://www.microchip.com/design-centers/embedded-security" target="_blank">Embedded Security Solutions</a></br>

Pre-provisioned ATECC608A Secure Element <a href="https://www.microchip.com/design-centers/security-ics/trust-platform/trust-go" target="_blank">(Trust & Go)</a></br>
Pre-configured and Pre-provisioned Secure Elements for Cloud Authentication. And propose for multiple cloud partners</br>
<img src="Doc/trustandgo_cloud.png" alt="drawing" width="570"/> </br>

Along <a href="https://microchipdeveloper.com/authentication:trust-platform" target="_blank">SAMA5D27-WLSOM1 Linux drivers for ATECC608A</a></br>
<a href="https://www.microchip.com/wwwproducts/en/ATECC608A" target="_blank">Product landing page</a></br></br>
<img src="Doc/atecc608a.png" alt="drawing" width="400"/> </br>

#### Wi-Fi<a name="step2d3"></a>

<a href="https://www.microchip.com/design-centers/wireless-connectivity/embedded-wi-fi" target="_blank">Wi-Fi Solutions</a></br>

WiFi link controller: <a href="https://www.microchip.com/en-us/development-tool/ev74a47a" target="_blank">WILCS02  Home page</a></br>
Same demonstrator could also work with Microchip combo Wifi + BLE: <a href="https://www.microchip.com/en-us/development-tool/ev74a47a" target="_blank">WILCS02  Home page</a></br>
<img src="Doc/wilc.png" alt="drawing" width="570"/> </br>

For the purpose of this demo, linux4wilc Github repo has been used for getting the WiFi WILC Firmware and Driver:</br>
- <a href="https://github.com/linux4wilc/firmware" target="_blank">WILC Firmware Version 3.0</a></br>
- <a href="https://github.com/linux4wilc/driver" target="_blank">WILC Driver 3.0</a></br>

<a href="https://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en599776" target="_blank">WILCS02  Wi-Fi Link Controller Linux User Guide</a></br>
<a href="http://ww1.microchip.com/downloads/en/DeviceDoc/ATWILC-Devices-Linux-Porting-Guide-User-Guide-DS70005329D.pdf" target="_blank">ATWILC Devices Linux Porting Guide</a></br>
<a href="https://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en601491" target="_blank">WILCS02  Evaluation Kit DesignFiles</a></br>
<a href="https://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en606209" target="_blank">ATSAMA5D27 SOM1 Kit1 User Guide</a></br>

#### Zigbee Network<a name="step2d4"></a>

<a href="https://www.microchip.com/wwwproducts/en/ATSAMR30M18" target="_blank">WBZ451PE module landing page</a></br> 

<img src="Doc/WBZ451PE.png" alt="drawing" width="570"/> </br>


## Do It Yourself<a name="step3"></a>

### Bill of materials<a name="step3a"></a>

- <a href="https://shop.sb-components.co.uk/products/piarm-the-diy-robotic-arm-for-raspberry-pi?variant=27857777098835" target="_blank">1x PiArm Robot with motor control board</a></br>
“PiArm”, DIY Robotic arm supporting Raspberry Pi from SB Components Ltd</br>
PiArm is a Raspberry Pi based DIY robotic arm outfitted with 6-axis digital computerized servo motors and 360 degrees of rotation liberation designed and developed for kids, makers, techies, and everyone.
    - PiArm features:
        - Fully metallic body
        - Equipped with 6-axis digital servo meters and 360 degrees of rotation system.
        - Easy to assemble and can be controlled by multiple devices like laptops, smartphones, joystick, etc.
        - Based on the Python language and the open-source code is available for secondary development.
        - Compatible with all versions of Raspberry Pi such as 4B, 3B+, 3, 2, A+, B, Zero W, Zero, etc.
    - Servo Features:
        - Python-based code capable of running on any platform like Linux or Windows.
	    - Connect the shield through a couple of options: through USB or through GPIO.
        - Power to provide a single power source to the Raspberry Pi and the PiArm.
<img src="Doc/piarm.png" alt="drawing" width="270"/>
<img src="Doc/piarm_dimensions.png" alt="drawing" width="270"/>

- <a href="https://www.amazon.fr/Microsoft-LifeCam-HD-3000-Webcam-720p/dp/B0096M4QOY/ref=sr_1_1?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&keywords=lifecam+microsoft+5000+HD&qid=1581350549&sr=8-1" target="_blank">1x LifeCam HD 3000 USB Camera from Microsoft</a></br>
This demo uses this solution from Microsoft but any USB webcam from the market can do the job.</br>
<img src="Doc/lifecam.png" alt="drawing" width="100"/></br>

- <a href="https://en.avm.de/products/fritzbox/fritzbox-7590/" target="_blank">1x Fritz!Box 7590 Router from AVM</a></br>
Top model Wifi Router from AVM portfolio</br>
<img src="Doc/fritzbox.png" alt="drawing" width="480"/></br>

- <a href="https://www.mikroe.com/secure-4-click" target="_blank">1x "Secure 4 Click" Click board from Mikroe</a></br>
Part of the well-known “Click board” family, Mikroe’s extension boards with over 700+ sensors, actuators, and connectivity (see full family <a href="https://www.mikroe.com/click" target="_blank">here</a>)</br>
The "SECURE 4 CLICK" includes the ATECC608A, a secure CryptoAuthentication™ device from Microchip. </br>It will bring our system security one step further.</br>
<img src="Doc/secure4click.png" alt="drawing" width="320"/></br>

- <a href="https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/ATSAMA5D27-SOM1-EK1" target="_blank">1x SAMA5D27-SOM1-EK1</a> / <a href="https://www.microchip.com/en-us/development-tool/ev40e67a" target="_blank">SAM9X60</a> / <a href="https://www.microchip.com/en-us/development-tool/ev31h43a" target="_blank">SAM9X75</a></br>

- ## SAMA5D27

The SAMA5D27 SOM1 Kit1 is a fast prototyping and evaluation platform for the high-performance 32-bit Arm® Cortex®-A5 processor-based MPU from Microchip running up to 500 MHz. Namely, the SAMA5D2-based System in Packages (SiPs) and the SAMA5D27 System-On-Module (SAMA5D27-SOM1). </br>
This kit comprises a baseboard with a soldered SAMA5D27-SOM1 module. </br>
This development kit will enable one or several of these functions, depending on the considered use cases (see later paragraph)</br>
    - First and foremost, drive the Robot and perform the pick & place pattern (all use cases)</br>
    - Manage the sensors network made of SAM R30M Xplained Pro Evaluation Kits (see use case 1, 2 & 3)</br>
    - Manage the USB camera : video streaming (see use case 1 & 3) and picture acquisition for visual inspection (see use case 2 & 3)</br>
    - Cloud connectivity (see use case 2, 3 & 4)</br>
<img src="Doc/som1-ek.png" alt="drawing" width="320"/></br>

- ## SAM9x60

The SAM9X60 Curiosity Development Board is based on the SAM9X60D1G SiP high-performance, low-power ARM926EJ-S CPU-based embedded microprocessor (MPU) running at 600MHz. The SAM9X60D1G Curiosity Development Board small form factor PCB including the SAM9X60D1G (SAM9X60 MPU plus 1Gb integrated DDR2), 4Gbit SLC NAND Flash, a KSZ8081 10/100 Ethernet PHY, and MCP16501 Power Management IC optimized for the module.   It is intended for evaluation of all variants of the SAM9X60 MPU, including the System in Package (SIP) variants and the System on Module (SOM).

<img src="Doc/sam9x60.png" alt="drawing" width="320"/></br>

- ## SAM9x75

The SAM9X75 Curiosity Development Board features a SAM9X75D2G MPU and is the evaluation platform for the SAM9X7 Series MPU devices. The SAM9X75D2G is a high-performance, ultra-low power ARM926EJ-S CPU-based embedded microprocessor (MPU) running up to 800 MHz, with an integrated 2 Gbit DDR3L memory. The device integrates powerful peripherals for connectivity and user interface applications, including MIPI DSI®, LVDS, RGB and 2D graphics, MIPI-CSI-2, Gigabit Ethernet with TSN, USB and CAN-FD. Advanced security functions are offered, such as tamper detection, secure boot, secure key storage, TRNG, PUF as well as high-performance crypto accelerators for AES and SHA.

<img src="Doc/sam9x75.png" alt="drawing" width="320"/></br>

- <a href="https://www.microchip.com/en-us/development-tool/ev74a47a" target="_blank">1x WILCS02 </a></br>
The WILCS02 Wi-Fi Link Controller SD Board makes it easy to connect to the cloud using a host MPU running Linux®. This SD board features the WILCS02PE, an IEEE® 802.11 b/g/n IoT link controller module.</br>
<img src="Doc/WILCS02-sd.png" alt="drawing" width="320"/></br>

- <a href="https://www.microchip.com/en-us/development-tool/ev96b94a" target="_blank">3x PIC32CX-BZ2 and WBZ451 Curiosity Development Board </a></br>

- The PIC32CX-BZ2 and WBZ451 Curiosity Board:
	- Offers integrated programming/debugging features using the PICkit™ On-board 4 (PKOB4) debugger interface
	- Requires only a Micro USB cable to power-up and program the board
	- Includes a mikroBUS Click™ header, which helps the users to expand the functionalities by connecting to various MIKROE mikroBUS™ Click board™ add-on boards
	- Performs rapid prototyping utilizing the Bluetooth LE and Zigbee-enabled RF module

- The PIC32CX-BZ2 and WBZ451 Curiosity Board supports a variety of applications:
	- Wireless lighting
	- Home automation or Internet of Things (IoT)
	- Industrial automation
	- Other Bluetooth LE or Zigbee-related applications.</br>
<img src="Doc/wbz451.png" alt="drawing" width="320"/></br>

- <a href="https://www.mikroe.com/6dof-imu-2-click" target="_blank">1x 6DOF IMU 2 Click </a></br>
6DOF IMU 2 Click is a compact add-on board for enhancing hardware prototypes with 6DOF functionality (6 degrees of freedom). This board features the BMI160, a small low-power inertial measurement unit (IMU) from Bosch Sensortec. It combines a state-of-the-art 3-axis low-g accelerometer and a low-power 3-axis gyroscope designed for 6-axis and 9-axis applications (additional magnetometer connection).</br>
<img src="Doc/imu2.png" alt="drawing" width="320"/></br>

- <a href="https://www.microchip.com/en-us/development-tool/EV96B94A" target="_blank">3x PIC32CX-BZ2 and WBZ451 Curiosity Development Board (AC164159)</a></br>
The PIC32CX-BZ2 and WBZ451 Curiosity Development Board, based on the WBZ451PE module. It comes preconfigured with an out-of-the-box multi-protocol demo application and features a temperature sensor, a current measurement header, an RGB LED and a MikroElectronika mikroBUSTM socket to attach a plethora of sensors and add-on boards.  Used here for our sensors network, monitoring key variables of our application (presence, temperature, vibration…). </br>
In this demo, we will program these boards with true zigbee firmware from Microchip (see <a href="https://www.microchip.com/en-us/products/wireless-connectivity/zigbee" target="_blank">Zigbee landing page</a>) and use on-board <a href="https://www.microchip.com/wwwproducts/en/AT30TSE758A" target="_blank">AT30TSE758A Digital Temperature Sensor</a>. This board could also be used to connect additional sensors such as accelerometers, and in such enables new use cases such as predictive maintenance.</br>
<img src="Doc/samr30mxpro.png" alt="drawing" width="480"/></br>

- <a href="https://www.amazon.fr/dp/B079QY57LN/ref=dp_prsubs_1" target="_blank">1x Emergency Button</a></br>
<img src="Doc/emergency_button.png" alt="drawing" width="100"/></br>

- Miscellaneous hardware</br>
    - USB Hub with external power source (Belkin F4U041UK)</br>
<img src="Doc/belkin_usb_hub.png" alt="drawing" width="320"/></br>
    - Micro USB Cables</br>
    - USB Type-C to USB Type-A Female Adapter (OTG)</br>
	- USB Power Charger</br>
	- 4x Cubes with 4x magnets (used for robot arm pick and place)</br>
	20mm x 2mm Coin magnets</br>
<img src="Doc/cube_with_magnet.png" alt="drawing" width="200"/></br>	
	- 16x magnets to put beneath the chessmate</br>
    - M3 X 10 mm Male-Female Brass spacer</br>
    M3 X 35mm Male to Female Brass Spacer</br>
    M3 Hex Nut Brass</br>
<img src="Doc/brass_spacer.png" alt="drawing" width="200"/></br>

### Step by step guide<a name="step3b"></a>

We started building the first robot arm over a prototype platform.</br>

<img src="Doc/robot_arm_box.png" alt="drawing" width="320"/></br>

<img src="Doc/robot_prototype_01.png" alt="drawing" width="200"/>
<img src="Doc/robot_prototype_02.png" alt="drawing" width="200"/></br>
And validated the demo ...</br>
<img src="Doc/robot_prototype_03.png" alt="drawing" width="200"/>
<img src="Doc/robot_prototype_04.png" alt="drawing" width="200"/>
<img src="Doc/robot_prototype_05.png" alt="drawing" width="200"/></br>
See one of the prototype in action:</br>
<a href="https://youtu.be/sZ-LExc-ZR4" target="_blank"><img src="Doc/robot_prototype_video.png" width="240" height="180" border="10" /></a></br>
Then from prototype to real demo, we integrated the whole solution into final casing.</br>
<img src="Doc/final_demo_casing_01.png" alt="drawing" width="200"/>
<img src="Doc/final_demo_casing_02.png" alt="drawing" width="200"/>
<img src="Doc/final_demo_casing_03.png" alt="drawing" width="400"/>
</br>

Support for the camera:</br>
<img src="Doc/final_demo_casing_camera_support.png" alt="drawing" width="300"/>
</br>

Drawing and dimensions:</br>
<img src="Doc/final_demo_casing_drawing.png" alt="drawing" width="300"/>
<img src="Doc/final_demo_casing_dimensions.png" alt="drawing" width="300"/>
</br>

Check out the Doc/Fixture Drawings.pdf file for the dimensions and 3D outlook of the final platform.</br>

Check the video posted on youtube:</br>
<a href="https://youtu.be/EOvJPf0HmIA" target="_blank"><img src="Doc/youtube_video.png" width="240" height="180" border="10" /></a>

### Hardware<a name="step3c"></a>

Boards connection:</br>
![](Doc/hardware_diagram.png)</br>
USB Hub is used to power some boards but also used to allow data communication between boards.</br>
Some boards have to be power supplied from independent power sources to avoid USB conflict in the demo due USB mounting enumeration.

### Software<a name="step3d"></a>

#### Linux Python Application<a name="step3d1"></a>

Checkout the application source code located into Software/Linux_Python_Application_public.zip package

- Application files:
    - iot_sam.py (main application file)
    - Eww_robo.py
    - Eww_robo_misc.py
    - Piarm.py
    - Serial_comm.py
- Robot calibration files:
    - Eww_robo_calib.json (file which contains the calibration data)
    - eww_robo_calibration.py (script file)

#### MiWi Mesh Application<a name="step3d2"></a>

From Software/MiWi.zip package, you are getting two Atmel Studio 7.0 projects.</br>

- ED_XMOD1 (End-Device): Project derived from ASFv3.47 MiWi Mesh EndDevice - WSN Demo Application (SAM R30 Module Xplained Pro)
- PAN_CORD_MOD (Pan-Coordinator): Project derived from ASFv3.47 MiWi Mesh PanCoordinator - WSN Demo Application (SAM R30 Module Xplained Pro)
</br>
The pan coordinator device creates the network and the end device perform an association in order to join the network.</br>
The end device transmits periodically the temperature information to the pan coordinator.

#### AWS Web Application<a name="step3d3"></a>

Checkout the dashboard source code located into Software/Dashboard_public.zip package.
</br>
You need an AWS account and your own certificates. 2 sets of certificate should be provided by AWS (one for the device, one for the web server application).

The package contains:
- HTML Web page (main.html)
- Python code for the web server (app.py). The application should run in AWS ec2-instance or run in local network. The images captured by the USB camera are sent over MQTT message and stored in S3 bucket cloud.

