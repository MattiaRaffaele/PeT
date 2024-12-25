import pyautogui
import time

time.sleep(3)

try:
    locatorCoordinates = pyautogui.locateOnScreen("locator.png")
    pyautogui.moveTo(locatorCoordinates)
    pyautogui.click()
except:
    try:
        tonocracyLogoLocation = pyautogui.locateOnScreen("tonocracyLogo.png")
        pyautogui.moveTo(tonocracyLogoLocation)
        pyautogui.click()
        locatorCoordinates = pyautogui.locateOnScreen("locator.png")
        pyautogui.moveTo(locatorCoordinates)
    except:
        pyautogui.alert(text='An error has accurred: the program is not able to find "tonocracyLogo.png"', title='Unexpected error', button='Exit')
        exit()


pyautogui.keyDown('down')
exit()