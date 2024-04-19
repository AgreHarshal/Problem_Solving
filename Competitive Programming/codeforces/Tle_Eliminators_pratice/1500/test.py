import cv2

# Load the image
image = cv2.imread('input_image.jpg')

# Define a rectangular region representing the area of interest (e.g., where the face is)
xmin, ymin, xmax, ymax = 100, 100, 300, 300

# Perform line clipping to eliminate background
def clip_line(x1, y1, x2, y2):
    # Compute region codes for the two endpoints of the line
    code1 = compute_region_code(x1, y1)
    code2 = compute_region_code(x2, y2)

    # Check if the line is completely outside the region
    if (code1 & code2) != 0:
        return None, None

    # Check if the line is completely inside the region
    if (code1 == 0) and (code2 == 0):
        return x1, y1, x2, y2

    # Apply Cohen-Sutherland algorithm to clip the line
    clipped_x1, clipped_y1 = clip_point(x1, y1, code1)
    clipped_x2, clipped_y2 = clip_point(x2, y2, code2)

    return clipped_x1, clipped_y1, clipped_x2, clipped_y2

def compute_region_code(x, y):
    code = 0
    if x < xmin:
        code |= 1
    elif x > xmax:
        code |= 2
    if y < ymin:
        code |= 4
    elif y > ymax:
        code |= 8
    return code

def clip_point(x, y, code):
    clipped_x, clipped_y = x, y
    if code & 1:
        clipped_y = y + (xmin - x) * (y2 - y1) / (x2 - x1)
        clipped_x = xmin
    elif code & 2:
        clipped_y = y + (xmax - x) * (y2 - y1) / (x2 - x1)
        clipped_x = xmax
    elif code & 4:
        clipped_x = x + (ymin - y) * (x2 - x1) / (y2 - y1)
        clipped_y = ymin
    elif code & 8:
        clipped_x = x + (ymax - y) * (x2 - x1) / (y2 - y1)
        clipped_y = ymax
    return int(clipped_x), int(clipped_y)

# Iterate through each pixel of the image and apply line clipping
for y in range(image.shape[0]):
    for x in range(image.shape[1]):
        # Apply line clipping to each pixel
        clipped_x, clipped_y, _, _ = clip_line(x, y, x, y)
        if clipped_x is None:
            # Set background pixels to black
            image[y, x] = [0, 0, 0]

# Display the resulting image
cv2.imshow('Clipped Image', image)
cv2.waitKey(0)
cv2.destroyAllWindows()
