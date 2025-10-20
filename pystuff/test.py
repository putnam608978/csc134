
import pygame
import sys

# Initialize Pygame
pygame.init()

# Set up the display
width, height = 600, 400
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Bouncing Chaos Symbol!")

# --- NEW: Create a clock to control framerate ---
clock = pygame.time.Clock()

# Load the Chaos symbol image (you need to have an image file for this)
chaos_image = pygame.image.load("chaos_symbol.png")  # Make sure this path is correct

# Get the size of the image for positioning
chaos_rect = chaos_image.get_rect()
chaos_rect.center = (width // 2, height // 2)  # Start in the middle of the screen

# --- NEW: Set up velocity (pixels per frame) ---
x_speed = 4
y_speed = 4

# --- Main Game Loop ---
running = True
while running:
    # Check for events (like closing the window)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # --- GAME LOGIC ---
    
    # Move the Chaos symbol based on its speed
    chaos_rect.x += x_speed
    chaos_rect.y += y_speed

    # --- NEW: Bouncing Logic ---
    
    # If the symbol's right edge hits the right wall OR its left edge hits the left wall
    if chaos_rect.right >= width or chaos_rect.left <= 0:
        x_speed = -x_speed  # Reverse the horizontal direction

    # If the symbol's bottom edge hits the bottom wall OR its top edge hits the top wall
    if chaos_rect.bottom >= height or chaos_rect.top <= 0:
        y_speed = -y_speed  # Reverse the vertical direction

    # --- DRAWING ---
    
    # Fill the screen with a color (black)
    screen.fill((0, 0, 0))

    # Draw the Chaos symbol at its new position
    screen.blit(chaos_image, chaos_rect)

    # Update the display
    pygame.display.flip()

    # --- NEW: Limit the game to 60 frames per second (FPS) ---
    clock.tick(60)

# Quit Pygame
pygame.quit()
sys.exit()
