open Jest;
open Expect;
open ReactTestingLibrary;
open Utils;

describe("Collapse", () => {
  test("should render correctly", () => {
    let wrapper = render(<Collapse title="title"> "content"->str </Collapse>);

    wrapper |> container |> expect |> toMatchSnapshot |> ignore;

    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });

  test("should work with subtitle and shadow", () => {
    let wrapper =
      render(
        <>
          <Collapse
            title="title" subtitle={Collapse.Component.string("subtitle")}>
            "content"->str
          </Collapse>
          <Collapse
            title="title"
            subtitle={Collapse.Component.string("subtitle")}
            shadow=true>
            "content"->str
          </Collapse>
        </>,
      );

    wrapper |> container |> expect |> toMatchSnapshot;
  });

  test("should work with initial visible", () => {
    let wrapper =
      render(
        <>
          <Collapse
            title="title" subtitle={Collapse.Component.string("subtitle")}>
            "content"->str
          </Collapse>
          <Collapse title="title" initialVisible=true>
            "content"->str
          </Collapse>
        </>,
      );

    wrapper |> container |> expect |> toMatchSnapshot;
  });

  // test("should throw error when title missing", () => {
  //   let errorMessage = ref("");

  //   let consoleSpy: MockJs.fn(string => unit, string, unit) = [%raw
  //     "jest.spyOn(console, 'error')"
  //   ];
  //   MockJs.mockImplementation(msg => errorMessage := msg, consoleSpy)
  //   |> ignore;

  //   render(
  //     <Collapse subtitle={Collapse.Component.string("subtitle")}>
  //       "content"->str
  //     </Collapse>,
  //   )
  //   |> ignore;

  //   consoleSpy |> mockRestore;

  //   errorMessage^ |> expect |> toContainString("required");
  // });

  testAsync("should expand when title clicked", finish => {
    let wrapper = render(<Collapse title="title"> "content"->str </Collapse>);

    wrapper |> container |> querySelector(".view") |> FireEvent.click;

    Js.Promise.(
      waitForElement(() => wrapper |> container |> querySelector(".expanded"))
      |> then_(_ =>
           wrapper
           |> container
           |> querySelectorAll(".expanded")
           |> expect
           |> toMatchSnapshot
           |> finish
           |> resolve
         )
      |> ignore
    );
  });
});
