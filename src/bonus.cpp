#include "bonus.h"

static const Color defaultColor = {0.36f, 0.38f, 0.7f, 1.0f};
static const Color ONE_UP_COLOR = {0.0f, 1.0f, 0.0f, 1.0f};
static const Color STICKY_RACKET_COLOR = {1.0f, 0.0f, 0.0f, 1.0f};

void drawBonus(Bonus *bonus)
{
	glPushMatrix();
	glTranslatef(bonus->coordinate.pos_x, bonus->coordinate.pos_y, bonus->coordinate.pos_z);

	glPushMatrix();

	glRotatef(bonus->rotation, 1.0f, 1.0f, 1.0f);
	drawCube(bonus->size, bonus->color);

	glPopMatrix();

	glPopMatrix();
}

void randomizeBonus(Bonus *bonus)
{
	// generate random position z -5.0 to 5.0
	bonus->coordinate.pos_z = static_cast<float>(rand() % 10) - (5.0f - bonus->size);

	// generate random position y -10 to 10
	bonus->coordinate.pos_y = static_cast<float>(rand() % 20) - (10.0f - bonus->size);
}

static void handleCollision(Bonus *bonus, Ball *ball, Racket *racket, Life *lifeCount, int index)
{
	if (bonus->coordinate.pos_x - bonus->size <= racket->coordinate.pos_x + racket->size &&
		bonus->coordinate.pos_x + bonus->size >= racket->coordinate.pos_x - racket->size &&
		bonus->coordinate.pos_y - bonus->size <= racket->coordinate.pos_y + racket->size &&
		bonus->coordinate.pos_y + bonus->size >= racket->coordinate.pos_y - racket->size)
	{
		printf("Bonus %d collected\n", bonus->id);

		switch (bonus->type)
		{
		case BonusType::ONE_UP:
			printf("Bonus 1UP collected\n");
			lifeCount->current = std::min(lifeCount->current + 1, lifeCount->max);
			break;

		case BonusType::STICKY_RACKET:
			printf("Bonus STICKY_RACKET collected\n");
			makeBallSticky(ball);
			break;
		default:
			printf("Mysterious bonus collected...\n");
			break;
		}

		bonus->coordinate.pos_x = 5.0f;
	}
}

void addBonus(std::vector<Bonus *> *bonus, BonusType type, int index)
{
	Bonus *newBonus = new Bonus;

	newBonus->id = index;
	newBonus->type = type;

	newBonus->size = 0.5f;
	newBonus->rotation = 0;

	switch (type)
	{
	case BonusType::ONE_UP:
		newBonus->color = ONE_UP_COLOR;
		break;
	case BonusType::STICKY_RACKET:
		newBonus->color = STICKY_RACKET_COLOR;
		break;
	default:
		newBonus->color = defaultColor;
		break;
	}

	newBonus->coordinate.pos_x = -40.0f;

	randomizeBonus(newBonus);

	bonus->push_back(newBonus);
}

void moveBonuss(std::vector<Bonus *> *bonus, Ball *ball, Racket *racket, Life *lifeCount, float movingSpeed, bool onKey)
{
	for (int i = 0; i < bonus->size(); i++)
	{
		Bonus *current = bonus->at(i);

		if (current->coordinate.pos_x > 0)
		{
			bonus->erase(bonus->begin() + i);
			return;
		}

		if (!onKey)
		{
			current->rotation = current->rotation >= 360 ? 0 : current->rotation + 1;
			current->coordinate.pos_z = sin(current->rotation * M_PI / 180);
			return;
		}

		current->coordinate.pos_x += movingSpeed;
		handleCollision(current, ball, racket, lifeCount, i);
	}
}

void generateBonus(int score, std::vector<Bonus *> *bonus)
{
	// Each 2000 points, spawn a 1UP bonus
	if (score % 2000 == 0)
	{
		addBonus(bonus, BonusType::ONE_UP, bonus->size());
	}
	// Each 5000 points, spawn a STICKY_RACKET bonus
	else if (score % 5000 == 0)
	{
		addBonus(bonus, BonusType::STICKY_RACKET, bonus->size());
	}

	if (score % 500 == 0)
	{
		printf("Your score reach: %d!\n", score);
	}
}

void drawBonuss(std::vector<Bonus *> *bonus)
{
	for (int i = 0; i < bonus->size(); i++)
	{
		drawBonus(bonus->at(i));
	}
}
