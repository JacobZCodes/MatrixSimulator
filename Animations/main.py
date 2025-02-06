from manim import *
class WriteEquations(Scene):
    def construct(self):
        name = Tex(r"$y=mx+b$",color = RED)
        self.play(Write(name), run_time=1)
        self.wait()

class BulletedListExample(Scene):
    def construct(self):
        blist = BulletedList("Item 1", "Item 2", "Item 3", height=2, width=2)
        blist.set_color_by_tex("Item 1", RED)
        blist.set_color_by_tex("Item 2", GREEN)
        blist.set_color_by_tex("Item 3", BLUE)
        self.add(blist)

class SceneOne(Scene):
    def construct(self):
        lineEq = MathTex("3x + 3y = -6")
        lineEq.shift(UP * 0.5)
        solvedEq = MathTex("y = -x - 2")
        self.play(Write(lineEq))
        self.play(Write(solvedEq))
        self.play(FadeOut(lineEq))
        self.play(FadeOut(solvedEq))
        axes = Axes(
        x_range=[-5, 5, 1],
        y_range=[-5, 5, 1],
        )
        self.play(Create(axes))
        graph = axes.plot(lambda x: -x-2, color=BLUE)
        self.play(Create(graph))
        self.play(FadeOut(axes,graph))
        # End scene
        secondEq = MathTex("6y - 12x = 18")
        self.play(Write(lineEq))
        self.play(Write(secondEq))
        self.play(FadeOut(lineEq))
        self.play(FadeOut(secondEq))
        # Write solved eqns
        self.play(Write(solvedEq))
        secondSolvedEqn = MathTex("y = 2x + 3")
        self.play(Write(secondSolvedEqn))
        axes = Axes(
        x_range=[-5, 5, 1],
        y_range=[-5, 5, 1],
        )
        self.play(Create(axes))
        graph1 = axes.plot(lambda x: -x-2, color=BLUE)
        graph2 = axes.plot(lambda x: 2*x+3, color=RED)
        self.play(Create(graph1))
        self.play(Create(graph2))
        self.play(FadeOut(graph1))
        self.play(FadeOut(graph2))
        self.play(FadeOut(solvedEq))
        self.play(FadeOut(secondSolvedEqn))
        question = "How do we find this point where the two lines cross without looking at a graph?"
        self.play(Write(question))




class Eq(Scene):
    def construct(self):
        unknownLetters = "abcdefghijklmnopqrstuvwxyz"
        expressionsToWrite = []
        cleanedExpressions = []
        with open("../output.txt","r") as f:
            for line in f:
                expressionsToWrite.append(line.split())
                if line == '\n':
                    break
        for ex in expressionsToWrite:
            newEx = []
            unknownLetterIndex = 0
            for num in ex:
                newTerm = str(num) + unknownLetters[unknownLetterIndex]
                newEx.append(newTerm)
                unknownLetterIndex += 1
            cleanedExpressions.append(newEx)
        
        for i,ex in enumerate(cleanedExpressions):
            if (not ex):
                continue
            # animate expresion here
            eq = MathTex(ex[0], "+", ex[1])
            eq.shift(UP * 0.5 * i)
            self.play(Write(eq))
            self.wait(1)

        return

        equation_1 = MathTex("w", "\\times","v", "=", "1")
        equation_1.shift(UP*2).scale(2)
        equation_2 = MathTex("v", "=", "w^{-1}")
        equation_2.scale(2)
        equation_3 = MathTex("w", "\\times","w^{-1}", "=", "1")
        equation_3.shift(UP*2).scale(2)

        self.play(Write(equation_1), Write(equation_2))
        self.wait(2)
        self.play(FadeOut(equation_1[2]))

        self.play(
            TransformMatchingShapes(
                VGroup(equation_1[0:2], equation_1[3:], equation_2[2].copy()),
                equation_3,
            )
        )