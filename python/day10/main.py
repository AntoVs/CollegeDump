import cv2

img = cv2.imread('luffy.jpg')
cv2.imshow("image",img)
cv2.waitKey(0)

#REsize & ROtate IMage
resize = cv2.resize(img,(400,400))
cv2.imshow("ResizedImg",resize)
cv2.waitKey(0)
rotate = cv2.rotate(resize,cv2.ROTATE_90_CLOCKWISE)
cv2.imshow("rotated",rotate)
cv2.waitKey(0)

#Filters
cv2.filter
