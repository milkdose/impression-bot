This tool is used for the automation of quick and simple product visuals for the promotional product industry.

HOW TO USE:
-Save a CSV version of your promotional product data including the individual product numbers and printing areas in the main directory. Info in the CSV is read as a string by the getline() function and deliminated by ','. The product number, title and print area will be displayed for the user to copy to the clip board if required by the client.

Save product images in the main directory, you can choose whether to write the product or logo image before or after the process. Print areas in the CSV file should maintain a format of: 'int' + ' ' + 'x' + ' ' + 'int' only.

-- Impression Visual Bot v1.0 --

HOW TO INSTALL:
-Please install dependancies using the provided python installer (as sudo) for mac only, linux users will have to install each one by hand.
-Windows version currently not available.

DEPENDENCIES:
-xcode command-line-tools
-Homebrew
-Opencv2
-Makefile
-g++
-pkg-config (for linking at copile time)

FUTURE CHANGES:
-Add option for multiple print areas such as engraving
-Convert EPS/SVG to jpg
-Find CMYK and output values to console
-Display warning if artwork exceeds maximum spot colout count
-Implement config file
-Windows compatibility
