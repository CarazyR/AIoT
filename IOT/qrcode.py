import pyzbar.pyzbar as pyzbar
from PIL import Image,ImageEnhance
image = "fuck.png"

img = Image.open(image)

img.show()

barcodes = pyzbar.decode(img)

for barcode in barcodes:
    barcodeData = barcode.data.decode("utf-8")
    print(barcodeData)