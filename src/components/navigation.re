module Link = Gatsby.Link;

[@bs.module] external style : Js.t({..}) = "./navigation.module.scss";

let component = ReasonReact.statelessComponent("Header");

let s = ReasonReact.stringToElement;

let activeClassName = "active";

let make = (~pathName, _children) => {
  ...component,
  render: _self => {
    let isHomePage = pathName == "/";
    let rootClassName = isHomePage ? style##root_home : style##root;
    <nav className=rootClassName>
      <ul className=style##list>
        <li className=style##linkHome>
          <Link to_="/" activeClassName> (s("Home")) </Link>
        </li>
        <li>
          <Link to_="/schedule/" activeClassName> (s("Schedule")) </Link>
        </li>
        <li>
          <Link to_="/speakers/" activeClassName> (s("Speakers")) </Link>
        </li>
        <li>
          <Link to_="/sponsors/" activeClassName> (s("Sponsors")) </Link>
        </li>
        <li> <Link to_="/about/" activeClassName> (s("About")) </Link> </li>
        <li> <Link to_="/blog/" activeClassName> (s("Blog")) </Link> </li>
        <li className=style##ticketsButton>
          <Button text="Buy a ticket" />
        </li>
      </ul>
    </nav>;
  }
};
